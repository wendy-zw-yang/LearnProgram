## 字符串string
### 字符串大小比较
函数形式：strcmp()
示例：
```
char s1[10]="";
char s2[10]=""; //strcmp()比较的是首地址's1'和's2'

//strcmp()函数比较的结果判断：
if(strcmp(s1,s2)>0)
    printf("s1>s2");

else if(strcmp(s1,s2)==0)
    printf("s1=s2");

else if(strcmp(s1,s2)<0)
    printf("s1<s2");
```

### 字符串拷贝
函数形式：strcpy()
示例：
```
char s1[100]="abccc"
char s2[10];
gets(s2);
strcpy(s1,s2); //将s2的值拷贝给s1
puts(s1);
```
s1,s2大小不一时，根据字符串数组的结尾'\0'来结束拷贝

### 字符串
函数形式：strcat()
示例：
```
char s1[100]="abccc"
char s2[10];
gets(s2);
strcpy(s1,s2); //将s2的值拷贝给s2
puts(s1);
```