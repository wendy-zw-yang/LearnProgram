//等级区分
/*#include <stdio.h>
int main()
{
    int score;
    char grade;
    scanf("%d",&score);
    if(score>=90)
        grade='A';
    else if(score<90 && score>=80)
        grade='B';
    else if(score<80 && score>=70)
        grade='C';
    else if(score<70 && score>=60)
        grade='D';
    else
        grade='E';
    printf("%d , grade = %c",score,grade);
    return 0;
}
*/
//switch结构
#include <stdio.h>
int main()
{
    int score;
    char grade;
    scanf("%d",&score);
    switch((int)score/10)
    {
        case 10:
        case 9: grade ='A';break; //10和9合并判断
        case 8: grade ='B';break;
        case 7: grade ='C';break;
        case 6: grade ='D';break;
        default: grade ='E';
    }
    printf("%c",grade);
}