//Узел                                      //// 
    typedef struct node 
    {
        char word (LENGTH+1);
        struct node* next;
    }
    node;
    
node* node1 = malloc(sizeof(node));
node1* word -> "one";
node1* next -> node2;


//хэш таблица                               ////
node* hashtable [500];


//считать слова из файла                    ////
node* new_node = malloc(sizeof(node));
fscanf(file, "%s", new_node->word)


//вставить слово в хэштаблицу               ////
new_node-> next =head;
head = new_node;


//вставить по порядку                       ////
node cursor = head;
while(cursor!=NULL)   
{
    if (cursor -> word < new_node ->next-> word) //если следующее слово больше нового
    {
        new_node->next = cursor->next;          //  вставляем его
        cursor->next = new_node;
        return true;
    }
    else
    cursor = cursor -> next;                    //иначе идем дальше по списку
}
if(cursor->next == NULL)                        //если это последнее слово
cursor->next = new_node;                        //вставляем новый узел в конец
//!!!! и тут же счетчиком считаем слово+1

// деревья                                  ////
    typedef struct node 
    {
        bool isword             // слово это чи не
        struct node children [27];
    }
    node;
node* root;


//вставляем в дерево                        ////
for(every dict word)
{
//разбиваем слово на буквы
//тут надо цикл для букв
//если первая буква есть,идем дальше
//если нет, создаем новый узел с номером буквы маллок
//если буква последняя, ставим галочку isword = true;
}

//!!!! и тут же счетчиком считаем слово+1
