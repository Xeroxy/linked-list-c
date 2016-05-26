#include"list.h"

int size(LL p){
    if(!p){
        return 0;
    }
    return 1+size(p->_next);
}
int ith(LL p, int index){ //Retourner le ième élément de la liste.
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
	printf("%d\t",p->_value); 
}
void print_dec(LL p){
    if(!p){
        return;
    }
    printf("%d\t",p->_value);
    print_dec(p->_next);
} 

void add_queue(LL* p, int value){  
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
int maximum(LL p){
	int max;
	LL tmp=p;
	max=tmp->_value; 
		for(tmp=p; tmp!=NULL; tmp=tmp->_next){
			if(tmp->_value>max){
				max=tmp->_value;
			}
		}
		return max;
}
int minimum(LL p){
	int min;
	LL tmp=p;
	min=tmp->_value; 
		for(tmp=p; tmp!=NULL; tmp=tmp->_next){
			if(tmp->_value<min){
				min=tmp->_value;
			}
		}
		return min;
}
double sort_ascending(LL p){
   int max; 
   LL tmp3=(LL)malloc(sizeof(LL));
   LL tmp1=(LL)malloc(sizeof(LL));
   LL tmp=p;

   for(tmp=p ; tmp!=NULL ; tmp=tmp->_next){
     tmp3=tmp;
     max=tmp->_value;
     for(tmp1=tmp->_next ; tmp1!=NULL ; tmp1=tmp1->_next){
        if(max < tmp1->_value){
           tmp3=tmp1; //Tmp3 est l'adresse de l'élement où se trouve le max.
           max=tmp3->_value;
        }	
     }
     tmp3->_value=tmp->_value; //Echange des 2 elements.
     tmp->_value=max;
	 print_inc(p); //Affiche les étapes du tri.
   }
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
    printf("Valeur du node %d: %d \n",value, ith(p, value));
}
void test(){
	LL tab1 = NULL;
	int tab[N]={12,2,0,3,55,88,42,26,17,8};
	int i;
	for (i=9;i>=0;i--){
		add_queue(&tab1,tab[i]);
	}
	display_size(tab1);
	printf("\n");
	print_inc(tab1);
	printf("\n");

	printf("Valeur max de la liste: %d\n", maximum(tab1));
	printf("\n");
	printf("Valeur min de la liste: %d\n", minimum(tab1));
	printf("\n");

	printf("Tri de la liste: \n");
	sort_ascending(tab1);
	printf("\n");

	if(delete_list(tab1)==NULL){
        printf("Linked list has been deleted.\n");  
    }
}

int main()
{
	test();
	system("pause");
}