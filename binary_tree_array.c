/*
implement a binary tree using arrays
perform tree traversals
print leaf nodes
print height of tree
*/

#include<stdio.h>
int complete_node = 15;
int tree[15]={8,9,15,55,3,8,10,99,6,'\0','\0',3,3,2,'\0'};
int max_val,min,sum=0;

int print_tree() {
  printf("\n");
  for (int i = 0; i < 15; i++) {
    if (tree[i] != '\0')
      printf(" %d ",tree[i]);
    else
      printf(" - ");
  }
  return 0;
}
int get_right_child(int index)
{
    if(tree[index]!='\0' && ((2*index)+2)<complete_node)
        return (2*index)+2;
    return -1;
}

int get_left_child(int index)
{
    if(tree[index]!='\0' && (2*index)+1<complete_node)
        return (2*index)+1;
    return -1;
}

void preorder(int index)
{
    if(index>=0 && tree[index]!='\0')
    {
        printf(" %d ",tree[index]);
        preorder(get_left_child(index));
        preorder(get_right_child(index));
    }
}
void postorder(int index)
{
    if(index>=0 && tree[index]!='\0')
    {
        postorder(get_left_child(index));
        postorder(get_right_child(index));
        printf(" %d ",tree[index]);
    }
}

void inorder(int index)
{
    if(index>=0 && tree[index]!='\0')
    {
        inorder(get_left_child(index));
        printf(" %d ",tree[index]);
        {
            if(max_val<tree[index])
                max_val=tree[index];
            if(min>tree[index])
                min=tree[index];
            sum=sum+tree[index];
        }
        inorder(get_right_child(index));
    }
}
void levelorder()
{
    int j;
    for(j=0;j<complete_node;j++)
    {
        if(tree[j]!='\0')
            printf(" %d ",tree[j]);
    }
}
int is_leaf(int index)
{
    if(!get_left_child(index) && !get_right_child(index)){
        return 1;
    }
    if(tree[get_left_child(index)]=='\0' && tree[get_right_child(index)]=='\0'){
        return 1;
    }
    return 0;
}

int get_max(int a, int b)
{
    return (a>b) ? a : b;
}

int get_height(int index)
{
    if(tree[index]=='\0' || index<0 || is_leaf(index))
        return 0;
    return(get_max(get_height(get_left_child(index)), get_height(get_right_child(index)))+1);
}


int main()
{
    print_tree();
    max_val=tree[0];
    min=tree[0];
    sum=0;
    printf("\nPreorder:\n");
    preorder(0);
    printf("\nPostorder:\n");
    postorder(0);
    printf("\nInorder:\n");
    inorder(0);
    printf("\nLevelorder:\n");
    levelorder();
    printf("\n");
    printf("\nheight of the tree is: %d\n",get_height(0));
    printf("\nMaximum : %d",max_val);
    printf("\nMinimum: %d",min);
    printf("\nSum: %d",sum);
    for(int i=0;i<complete_node;i++)
    {
      if(tree[i]!='\0'){
        if(is_leaf(i))
          printf("\n%d is a leaf node",tree[i]);
      }
    }
    printf("\n");
}
