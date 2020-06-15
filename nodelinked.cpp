#include <iostream>
#include "nodelinked.h"

Node::Node(int element)
{
    this->element = element;
    this->next = nullptr;
}

LinkedList::LinkedList()
{
    this->sizee = 0;
    this->head = nullptr;
}
void LinkedList::add(int elem)
{
    Node *node = new Node(elem);
    if (head == nullptr){
        head = node;
        sizee++;
        return;
    }
    Node *ctrl=head;
    Node *c = nullptr;
    while (ctrl != nullptr)
    {
        if(ctrl->element > node->element)
            break;
        else{
            c = ctrl;
            ctrl = ctrl->next;
        }
    }
    if(ctrl == head)
    {
        node->next = head;
        head = node;
    }
    else
    {
            node->next = ctrl;
            c->next = node;
    }
    sizee++;

}

void LinkedList::del(int num)
{
    if (head == nullptr){
        std::cout << "lista vacia, sin elementos\n";
        return;}
    Node *ctrl = head;
    Node *c = nullptr;
    while(ctrl!=0){
			if(ctrl->element==num)
				break;
			else{
				c=ctrl;
				ctrl=ctrl->next;
			}
		}
    if(ctrl == 0)
    {
        std::cout <<"no se encontro el numero\n";
    }
    else{
        if (head==ctrl)
            head = head->next;
        else
            c->next = ctrl->next;
        delete ctrl;
        sizee--;
    }
}

void LinkedList::show()
{
    Node *iter = head;
    while(iter != nullptr)
    {
        std::cout <<  iter->element << " ";
        iter = iter->next;
    }
    std::cout <<"\n";
}

int main()
{
    LinkedList *lista = new LinkedList;
    int au = 0;
    int au2 = 0;
    bool c = false;
    std::cout << "bienvenido a linked list, aqui podras guardar y sacar tus numeros enteros, y lo mejor es que estaran ordenados para una busqueda mas comoda!!!\n";
    while(!c)
    {
        std::cout << "elige que quiere hacer: \n\n (0) salir\n (1)insertar numero\n (2)sacar numero\n";
        std::cin >> au2;
        switch(au2)
        {
        case 0:{
            std::cout << "gracias por el servicio";
            c = true;
            break;}
        case 1:{
            std::cout << "elige el numero: ";
            std::cin >> au;
            lista->add(au);
            break;}
        case 2:{
            std::cout << "que numero quieres remover?\n";
            std::cin >> au;
            lista->del(au);
            break;}
        }
        std::cout << " esta es su lista\n\n";
        lista->show();
    }
}
