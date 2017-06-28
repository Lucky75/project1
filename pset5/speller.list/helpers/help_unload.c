//выгрузка хэштаблицы

node* cursor = head;
while(cursor!=NULL)
{
    node* temp = cursor;
    cursor=cursor->next;
    free(temp);
}


//высадка дерева
//вырубить все указатеди детей, а потом выше. Рекурсия

// запуск валгринда
valgrind -v --leak-cheak=full ./speller ~cs50/pset5/texts/austinpowers.txt