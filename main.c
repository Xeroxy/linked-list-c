#include"list.h"

int size(LL p){
    if(!p){
        return 0;
    }
    return 1+size(p->_next);
}
double ith(LL p, int index){ //Retourner le ième élément de la liste.
    if(index==1){               //Condition de base
        return p->_value;
    }
    return ith(p->_next, index-1);
}
void print_inc(LL p){
	if(!p){
		return;
	}
	print_inc(p->_next);
	printf("%.2f\t",p->_value);
}
void print_dec(LL p){
    if(!p){
        return;
    }
    printf("%.2f\t",p->_value);
    print_dec(p->_next);
}

void add_queue(LL* p, double value){  
    LL newP = (LL)malloc(sizeof *newP);
    if (newP != NULL){
      newP->_next = NULL;
      newP->_value = value;
      if (*p == NULL){
          *p = newP;
        }
      else {
          LL tmpP = *p;
          while (tmpP->_next != NULL){
              tmpP = tmpP->_next;
            }
          tmpP->_next = newP;
        }
    }
}
void sort_ascending(LL p){
   double min; 
   LL tmp3=(LL)malloc(sizeof(LL));
   LL tmp1=(LL)malloc(sizeof(LL));
   LL tmp=p;
 
   for(tmp=p ; tmp!=NULL ; tmp=tmp->_next){
     tmp3=tmp;
     min=tmp->_value;
     
     for(tmp1=tmp->_next ; tmp1!=NULL ; tmp1=tmp1->_next){
        if(min < tmp1->_value){
           tmp3=tmp1; //Tmp3 est l'adresse de l'élement où se trouve le minimum.
           min=tmp3->_value;
        }
     }
     tmp3->_value=tmp->_value; //Echange des 2 elements
     tmp->_value=min;
   }
}

double delete_top(LL *p){
    double val;
    LL *tmp=(LL*)malloc(sizeof(list)); //Element temporaire de type cell*.
    if(!tmp){
        return -1; //Retourne -1 si la pile est vide.
		exit(EXIT_FAILURE);}
    *tmp=(*p)->_next; 
    val=(*p)->_value;
    free(*p);
    *p=*tmp;
    return val;
}

LL delete_list(LL p){
    LL tmp = p;
    LL tmpnext;
    while(tmp!=NULL){
        tmpnext=tmp->_next;
        free(tmp);
        tmp=tmpnext;
    }
    return NULL;
}
void display_size(LL p){
    printf("Size of my list: %d\n", size(p));
}
void display_ith(LL p){
    int value;
    printf("Position de la valeur recherchee: ");
    scanf("%d",&value);
    printf("Valeur du node %d: %.2f \n",value, ith(p, value));
}
void test(){
	LL tab1 = NULL;
	double tab[N]={2.50,13.40,0.15,7.90,10.00,66.66,22.50,9.00,45.45,15.58};
	int i;
	for (i=9;i>=0;i--){
		add_queue(&tab1,tab[i]);
	}
	display_size(tab1);
	printf("\n");

	printf("-----Supprime le sommet----- \n");
	print_dec(tab1);
	printf("Valeur supprimee: %.2f\n",delete_top(&tab1));
	display_size(tab1);
	printf("\n");

	printf("-----Supprime le dernier----- \n");
	delete_top(&tab1);
	printf("Valeur supprimee: %.2f\n", ith(tab1, 8));
	display_size(tab1);
	printf("\n");

	printf("-----Liste triee----- \n");
	sort_ascending(tab1);
    print_inc(tab1);
	printf("\n");
	printf("\n");

	printf("-----Renvoi la valeur du ieme element de la liste----- \n");
	print_dec(tab1);
	printf("\n");
	display_ith(tab1);
	printf("\n");

	if(delete_list(tab1)==NULL){
        printf("Linked list has been deleted.\n");  
    };
}

int main()
{
	test();
	system("pause");
}