<?php

    require(__DIR__ . "/../includes/config.php");

    // ensure proper usage
    if (empty($_GET["lat"]))
    {
        http_response_code(400);
        exit;
    }
    if (empty($_GET["lng"]))
    {
        http_response_code(400);
        exit;
    }

    // escape user's input
    $lat = urlencode($_GET["lat"]);
    $lng = urlencode($_GET["lng"]);
    
    // numerically indexed array of articles
    $articles = [];
    
    // headers for proxy servers
    $headers = [
        "Accept" => "*/*",
        "Connection" => "Keep-Alive",
        "User-Agent" => sprintf("curl/%s", curl_version()["version"])
    ];

    // download RSS from Google News
    $context = stream_context_create([
        "http" => [
            "header" => implode(array_map(function($value, $key) { return sprintf("%s: %s\r\n", $key, $value); }, $headers, array_keys($headers))),
            "method" => "GET"
        ]
    ]);
    $contents = @file_get_contents("http://api.timezonedb.com/v2/get-time-zone?key=4XDNPID893QW&format=xml&by=position&lat={$lat}&lng={$lng}", false, $context);
    if ($contents === false)
    {
        http_response_code(503);
        exit;
    }

    // parse RSS
    $rss = @simplexml_load_string($contents);
    @fclose($handle);
    if ($rss === false)
    {
        http_response_code(500);
        exit;
    }
//var_dump($rss);
    // iterate over items in channel
    //foreach ($rss as $item)
    //{
        // add article to array
        $articles[] = [
            "timestamp" => (string) $rss->timestamp,
            "formatted" => (string) $rss->formatted
        ];
    //}

    // output articles as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($articles, JSON_PRETTY_PRINT));

?>
