# MyCproject

## 前言
C语言项目，大一上学期写的一个十分简陋的学生信息管理系统

项目地址：[Chord的C语言项目实践](https://github.com/ChordXD/MyCproject)

## 项目实践报告原文

### 一、需求分析
制作一个学生成绩的管理系统，包括实现以下功能：1、输入数据。2、显示数据。3、查找数据。4、增加一条数据。5、删除一条数据。6、退出。
同时，应充分考虑界面设计与用户交互体验，设计一个近似于可视化设计的系统程序，增强用户使用体验。
### 二、系统设计
#### （一）系统中的数据定义
对于每一个学生的成绩，使用结构体数组存储数据。

存储的数据数据类型分别为：

学号：long long int.

姓名：char型数组。

班级：char 型数组。

高数：int.

英语：int.

总分：int.

其他数据视实际使用情况而定义。

#### （二）系统的概要设计
欢迎界面--->初始化数据--->从文件中读取数据--->用户交互，处理数据--->结束，保存数据--->退出程序

#### （三）系统的详细设计
##### 欢迎界面

欢迎界面是通过文件操作从设定好的路径读取一个文本文件，通过fgetc函数和putchar函数分别读取和打印预先在文本文件当中设定好的字符画来展示一个欢迎界面。

##### 初始化数据。

通过调用预先写好的初始化函数，在内存中预分配一个足够大的临时数组准备存放来自文件当中的学生信息及数据。同时初始化学生的人数，读取和保存的时候准备写入的文件文件名。
##### 从文件中读取数据

通过fopen函数打开文件，后在通过fscanf函数从文件当中读取数据至预先在内存中初始化好的结构体数组之中，同时计算出从文件当中读取了多少学生的数据。

若出现异常，及时中断，输出错误信息并根据用户的选择进行下一步处理。

##### 用户交互，数据处理
展现预先准备好的交互界面，根据用户的选择进行数据处理。
###### 增加数据

根据学号通过顺序查找找出第一个大于该学生编号的学生数据，获取其在内存中临时数组的编号，并将其全部后移一位，在将当前学生数据覆盖此人数据，完成插入操作。
若出现异常，及时中断，输出错误信息并根据用户的选择进行下一步处理。

###### 删除数据

增加数据的反向操作。先通过二分查找到预删除学生数据的编号，然后将该学生数据编号之后的数据向前移动一位进行覆盖操作，最后将学生总人数减少一个。
若出现异常，及时中断，输出错误信息并根据用户的选择进行下一步处理。

###### 查询数据

通过二分查找找到学生学号所对应在内存中数据的临时编号，并显示。
若出现异常，及时中断，输出错误信息并根据用户的选择进行下一步处理。

###### 显示所有数据

顺序输出内存中目前为止的全部数据即可。
若出现异常，及时中断，输出错误信息并根据用户的选择进行下一步处理.

###### 退出
退出当前模块。

##### 保存数据。

通过fprintf将内存中的临时数据全部写入预先准备好的文件当中。
若出现异常，及时中断，输出错误信息并根据用户的选择进行下一步处理。

#### 系统的核心算法
*二分查找*

二分查找即通过折半二分的思想，大大减少了查找所需的时间。其时间复杂度为O(logn),空间复杂度为O(log2^N)。
```c++
array[10086]; //简单的模板如下。
int  bSearch(int begin,int end,int aim)
{
    int first=begin,last=end,middle;
    while(first<=last){
        middle = (first + last)/2;
        if(array[middle]==aim) return aim;
        else if(array[middle] > aim) last = middle - 1;
        else first = middle + 1;
    }
    return -1;
}
```

### 三、系统编码及运行

#### （一）系统开发涉及的软件
	Microsoft Visual Studio Community 2017 版本 15.5.2 
#### （二）系统运行界面及结果

##### 1、初始界面
![初始界面](https://github.com/ChordXD/MyCproject/1.png)

##### 2、显示所有学生成绩
![显示所有学生成](https://github.com/ChordXD/MyCproject/2.png)
 
##### 3、查询学生成绩
 ![查询学生成绩](https://github.com/ChordXD/MyCproject/3.png)

##### 4、增加一个学生的成绩。
 ![增加一个学生的成绩](https://github.com/ChordXD/MyCproject/4.png)

##### 5、删除一个学生的成绩
 ![删除一个学生的成绩](https://github.com/ChordXD/MyCproject/5.png)

##### 6、退出
![退出](https://github.com/ChordXD/MyCproject/6.png)

### 四、系统测试

第一次运行程序时,没有建立任何数据库文件，系统会自动建立一个数据文件，并给出想应的提示：

**程序：**

欢迎使用本程序！检测到第一次使用该程序，正在为您构建所需文件，请稍后……

构建成功！

*注：此时数据库中没有任何数据，即若显示所有成员成绩，查询，删除时均
会出现异常，此时程序会出现错误提示*

**输入：** 1

**程序：**

数据库中没有任何学生信息！请先添加，再进行操作！

是否立刻添加？

是：请输入 1 。否，并返回上一级菜单：请输入 2 。

**【并发出报警声】**

您的选择：

*注：为了测试其他功能的异常处理，我们这里输入2。*

输入：2

输入：2

**程序：**

数据库中没有任何学生信息！请先添加，再进行操作！

是否立刻添加？

是：请输入 1 。否，并返回上一级菜单：请输入 2 。

**【并发出报警声】**

**输入：** 2

**输入：** 4

**程序：**

数据库中没有任何学生信息！请先添加，再进行操作！

是否立刻添加？

是：请输入 1 。否，并返回上一级菜单：请输入 2 。

**【并发出报警声】**

*注：数据库中无数据的异常测试均通过。*

**输入：** 1

**输入：** 3

**程序：**

请输入一组学生的数据：

学号：**输入：** 1714010217

姓名：**输入：** 彭睿杰

班级：**输入：** 软件17-2

数学成绩：**输入：** 100

英语成绩：**输入：** 100

添加成功，当前已录入学生数量为1。

是否继续添加？

继续添加：请输入1。结束添加：请输入2。

**输入：** 1

请输入一组学生的数据：

学号：**输入：** 1

姓名：**输入：** text1 

班级：**输入：** 软件17-2

数学成绩：**输入：** 20

英语成绩：**输入：** 30

添加成功，当前已录入学生数量为2。

是否继续添加？

继续添加：请输入1。结束添加：请输入2。

**输入：** 2

*注：至此我们成功添加了两组数据，数据添加功能完好。*

**输入：** 1

*注：此处程序会按照学号进行排序显示所有数据库中的数据*

**程序：**

| 学号	|			姓名	|	班级	|	高数分数	|英语分数	|总分|
|:-----------:|:----:|:------:|:------:|:-------:|:-----:|
|1				|	text1	|	软件17-2	|20	|		30			|50|
|1714010217		|	彭睿杰		|软件17-2	|100		|	100			|200|

快捷操作：

1、	删除数据。

2、	添加数据。

3、	查找数据

4、	什么也不做，返回上一级菜单。

*注：此处显示所有学生成绩的功能测试完毕，快捷操作中的各个功能完全等于主菜单的各个功能，此处不再一一测试。*

**输入：** 4

**输入：** 2

**程序：**请输入你需要查找的同学的学号：输入：2

**程序：**

错误！查无此人！

是否继续查询：

继续查询：请输入1 。

结束查询，并返回上一级：请输入2。

**输入：** 1

**程序：**

请输入你需要查找的同学的学号：输入：1714010217

**程序：**

|学号	|	姓名	|	班级|		高数分数|	英语分数|	总分|
|:--:|:----:|:----:|:-----:|:--:|:---|
|1714010217|			彭睿杰	|	软件17-2|	100|			100|			200|

是否继续查询：

继续查询：请输入1 。

结束查询，并返回上一级：请输入2。

注：查询功能测试完毕，异常处理及正常查询皆可正常运行。

**输入：** 2

**输入：** 4

**程序：**请输入要删除学生的学号：**输入：** 2

**程序：**

错误！查无此人！

是否重新删除？

重新删除：请输入1。结束删除：请输入2。

**输入：** 1

请输入要删除学生的学号：**输入：** 1

**程序：** 删除成功！当前以录入学生的数量为1。

是否继续删除？

继续删除：请输入1。结束删除：请输入2。

您的选择：**输入：** 2

*注：至此删除功能测试完毕。*

**输入：** 5

保存成功，共保存了1个数据。

**【程序退出】**

*注：再文件的根目录的data.txt中，可以找到本次操作保存的数据。文件保存测试完毕。至此，程序所有功能测试完毕*


### 五、总结
项目实践是锻炼编程能力的一个很好的机会，从零到一个程序的实现，需要设计，思考，查找资料，编写，以及调试与总结，前前后后不仅是对单个编程能力的实现，也是对所有所学知识的一个综合运用和实现。

本次项目实践收获颇丰，大幅度锻炼了我的代码实现能力，也使我更加进一步的理解了程序结构化编程的原理。

本程序是大学生活的一个开端，也是程序之路上面的一个良好的出发点。

通过本程序，我更进一步熟悉了老师上课所讲的知识，在数据管理，文件操作方面也有了自己的创新与实践。

我更进一步的学习了字符串处理，数组操作，利用指针等一系列基础操作，为我以后的学习打下了深厚的基础。

感谢马超老师一直以来的辛勤教导与在本程序上的指导，也感谢所有在程序开发过程中给与我灵感与建议的学长与同学们。

最后，天道酬勤，感谢一直付出的自己。


### 附录（源代码）
```c++
/*
头文件
文件名：data_get.h
*/
#pragma once
#ifndef DATA_GET_H_INCLUDED
#define DATA_GET_H_INCLUDED //防止头文件重复。

/*文件输入函数*/

void get_data(void);//从目标文件流读取数据。

#endif // !DATA_GET_H_INCLUDED
/*
文件名：data_manage.h
*/
#pragma once
#ifndef DATA_MANAGE_H_INCLUDED
#define DATA_MANAGE_H_INCLUDED

/*此头文件包含数据库管理的全部所需函数。*/

void initialize_data(void);//系统初始化。

void add_data(void);//增加数据。

int find_data(long long aim);//根据学号查找数据。

void del_data(void);//删除一条数据

void display_find_data(void);//显示查找数据。

void print(int aim);//打印一条数据。

void put_all(void);//打印所有数据。

int zero_data(void);//数据库没有数据时的异常处理。

void user_choose(void);//用户交互，

void save(void);//保存数据。

#endif // !DATA_MANAGE_H_INCLUDED

/*
文件名：data_manage_p.h
*/

#pragma once
#ifndef DATA_MANAGE_P_H_INCLUDED
#define DATA_MANAGE_P_H_INCLUDED

/*此头文件为本系统的数据结构：结构体数组。
优点：易于管理，（二分）查找较快与方便。
缺点：较为耗费内存资源。
*/

#define NAME_MAX_SIZE (100)//名称最大值的宏定义
#define DATA_MAX (100000)//内存中的缓存数据，也是该系统最大可以存储与读取的学生信息数量。

/*本系统没有检查数组越界的功能*/

//学生信息结构体。
typedef struct {
	long long id;
	char name[NAME_MAX_SIZE];
	char CLASS[NAME_MAX_SIZE];
	int math;
	int english;
	int sum;
}Student;

//此三项可在initialize.c中找到，为系统必不可缺的数据信息。
extern char sign[];//数据保存的文件名。
extern Student student[];//内存中初始化的结构体数组。
extern int number;//实时的学生数量。

#endif //!DATA_MANAGE_P_H_INCLUDED

/*
文件名：ui.h
*/
#pragma once
#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

/*字符图片处理函数*/

void get_photo(char *file_name);//读取目标文件中的字符图片，并显示。

void head_ui(void);//欢迎字符图片。

void direction_ui(void);//交互提示信息图片。

#endif // !UI_H_INCLUDED

/*
源文件
文件筛选器：data_union
文件名：data_add.c
*/

#include <stdio.h>
#include "data_manage_p.h"

static void shift_array(int index)
{
	int src; //被赋值元素的索引。

	for (src = number - 1; src >= index; src--) {
		student[src + 1] = student[src];
	}
	number++;
}

int choose_temp;

void add_data(void)
{
mark:;
	Student temp;//临时储存。
	/*新添加学生数据的读取*/
	printf("请输入一组学生的数据：\n");
	printf("学号："); scanf("%lld", &temp.id);
	printf("姓名："); scanf("%s", temp.name);
	printf("班级："); scanf("%s", temp.CLASS);
	printf("数学成绩："); scanf("%d", &temp.math);
	printf("英语成绩："); scanf("%d", &temp.english);
	temp.sum = temp.math + temp.english;
	int i;
	int error = 0;

	for (i = 0; i < number; i++) {//学号查重（顺序查找）。
		if (student[i].id >= temp.id) {
			if (student[i].id == temp.id) error = 1; //学号相同！错误！
			break;//此时i中恰好存储了该学生按照学号从小到大排序应插入的位置。
		}
	}
	if (error == 1) {
		printf("\a学号不可相同。\n");
		printf("是否重新添加？\n重新添加：请输入 1 。结束添加：请输入 2 。\n您的选择：");

		scanf("%d", &choose_temp);

		if (choose_temp == 1) goto mark;
	}
	else {
		shift_array(i);//数据移动，将该新增学生的数据应插入位置之后的学生的数据全部顺序移动。
		student[i] = temp;//数据插入。

		printf("添加成功，当前已录入学生数量为%d。\n", number);
		printf("是否继续添加？\n继续添加：请输入 1 。结束添加：请输入 2 。");
		
		scanf("%d", &choose_temp);

		if (choose_temp == 1) goto mark;
		
	}

}

/*
文件名：data_del.c
*/

#include <stdio.h>
#include "data_manage_p.h"
#include "data_manage.h"

static void shift_array(int index)
{
	int src; //被赋值元素的索引。

	for (src = index ; src <= number - 1 ; src++) {
		student[src] = student[src+1];//前移
	}
	number--;//总人数减少。
}

int choose_temp;

void del_data(void)
{
mark:;
	if (zero_data() == -1) goto end;//数据库中没有数据。
	long long aim;
	printf("请输入要删除学生的学号：");
	scanf("%lld", &aim);
	int i = find_data(aim); //使用二分查找查询该学号是否存在。
	if (i != -1) {
		shift_array(i);//数据移动，将该数据后面的元素前移，覆盖该元素。
		printf("删除成功！当前已录入学生数量为%d。\n",number);
	}
	else {
		printf("错误！查无此人！\n");
		printf("是否重新删除？\n重新删除：请输入 1 。结束删除：请输入 2 。");

		scanf("%d", &choose_temp);

		if (choose_temp == 1) goto mark;
	}
	printf("是否继续删除？\n继续删除：请输入 1 。结束删除：请输入 2 。\n");
	printf("您的选择：");
	scanf("%d", &choose_temp);

	if (choose_temp == 1) goto mark;
end:;

}

/*
文件名：data_display.c
*/

#include <stdio.h>
#include "data_manage.h"
#include "data_manage_p.h"

void print(int aim)
{
	printf("%-20lld   %-10s %-10s %-10d %-10d %-10d\n", student[aim].id, student[aim].name,
		student[aim].CLASS, student[aim].math,
		student[aim].english, student[aim].sum);//格式化输出所有学生数据。
}

void put_all(void)
{
	if (zero_data() == -1) goto end;//若没有数据，执行此段。
	printf("学号                   姓名       班级       高数分数   英语分数   总分\n");
	for (int i = 0; i < number; i++)
		print(i);//循环打印所有数据。
	printf("快捷操作：\n1、删除数据。\n2、添加数据。\n3、查找数据\n4、什么也不做，返回上一级菜单。\n");
	int choose_put;
	printf("您的选择：");
	scanf("%d", &choose_put);
	switch (choose_put)
	{
	case 1:del_data(); break;
	case 2:add_data(); break;
	case 3:display_find_data(); break;
	case 4:break;
	default:printf("请输入正确的操作数字！\a");
		break;
	};
end:;
}

/*
文件名：data_find.c
*/

#include "data_manage_p.h"
#include <stdio.h>
int find_data(long long aim)//二分查找。
{
	int first = 0;
	int last = number - 1;
	
	while (first <= last) {
		int middle = (first + last)/2;//取中间数据的下标
		if (student[middle].id == aim) return middle;//若找到，返回下标。
		else if (student[middle].id < aim) first = middle + 1;//若下标值对应的数据比目标值小，则将下一次的开始下标改为现在的中值下标+1。
		else last = middle - 1;//同事，操作相反。
	}
	return -1;//若整个数据中都未找到，返回异常值-1 。

}

void display_find_data(void)
{
mark:;
	if (zero_data() == -1) goto end;//异常，数据中没有任何数据。
	long long temp;
	printf("请输入你需要查找的同学的学号：");
	scanf("%lld", &temp);
	int i = find_data(temp); //使用二分查找查询该学号是否存在,并且获得该数据的下标。
	if (i != -1) {
		printf("学号                   姓名       班级       高数分数   英语分数   总分\n");
		print(i);
	}
	else 
		printf("错误！查无此人！\n");//没有找到。
	printf("是否继续查询：\n继续查询：请输入 1 。\n结束查询，并返回上一级：请输入 2 。\n");
	int temp_choose;
	scanf("%d", &temp_choose);
	if (temp_choose == 1) goto mark;//根据用户选择重新定向。
end:;//异常处理标识。
}

/*
文件名：data_get.c
*/

#include <stdio.h>
#include <Windows.h>
#include "data_manage_p.h"

static FILE *open(void)
{
	static error(void);

mark:;
	FILE *fp;
	if ((fp = fopen(sign, "r")) == NULL) {
		printf("欢迎使用本程序！检测到第一次使用该程序，正在为您构建程序所需文件，请稍后.....\n");//无法打开文件。
		if((fp = fopen(sign, "w"))!=NULL){//以只写模式打开文件，此时文件不存在，则会自动创建一个数据文件。
			fclose(fp);
			Sleep(500);//增加使用体验。
			puts("构建成功！");
			goto mark;//重新以只读模式打开。
		}
		else
			error();//出错。
	}
	else {
		printf("欢迎！正在初始化，请稍后.....\n");
		Sleep(1000);
		return fp;
	}

}

static error(void)
{
	puts("失败！\a是否重新构建？");
	printf("1，重新尝试构建。\n2、退出。\n");
	int choose;
	scanf("%d", &choose);
	if (choose == 1)
		open();
	else
		exit(1);//直接退出。
}

void get_data(void)
{
	FILE *fp = open();//打开文件
	while (fscanf(fp, "%lld %s %s %d %d %d\n", &student[number].id, student[number].name,
		student[number].CLASS, &student[number].math,
		&student[number].english, &student[number].sum) != EOF) {//格式化读取文件流的学生信息。
		number++;//每成功读取一个学生信息，学生数量增加一个。
	}
	printf("初始化成功！共读取%d个学生数据！\n", number);
	fclose(fp);

}

/*
文件名：data_initialize.c
*/

#include <stdio.h>
#include "data_manage_p.h"

Student student[DATA_MAX];//在内存中创建一个DATA_MAX大小的临时储存数组，存放学生数据。
char sign[] = "data.txt";//数据文件的文件名
int number;//学生数量
int user_number;

void initialize_data(void)
{
	user_number = 0;
	number = 0;//初始化学生数量。	
}

/*
文件名：data_save.c
*/

#include "data_manage_p.h"
#include <stdio.h>

void save(void)
{
	FILE *fp;
	if ((fp = fopen(sign, "w")) == NULL) {//以只写模式打开文件，同时删除文件中上一次的数据。
		printf("\a保存失败！");//打开失败。
	}
	else {
		for (int i = 0; i < number; i++) {
			fprintf(fp, "%lld %s %s %d %d %d\n", student[i].id, student[i].name,
				student[i].CLASS, student[i].math,
				student[i].english, student[i].sum);//将内存中的学生数据格式化打印到文件当中。
		}
		printf("保存成功，共保存了%d个数据。\n", number);
		fclose(fp);
	}

}

/*
文件名：data_zero.c
*/

#include <stdio.h>
#include "data_manage_p.h"

int choose_temp;
int zero_data(void)
{
	if (number == 0) {
		printf("数据库中没有任何学生信息！请先添加，再进行操作！\n\a");
		printf("是否立刻添加？\n是：请输入 1 。否，并返回上一级菜单：请输入 2 。\n");
		printf("您的选择：");
		scanf("%d", &choose_temp);
		if (choose_temp == 1) add_data();//若用户想要添加数据，转到数据添加函数。
		return -1;//返回异常值-1。
	}
	return 1;//若数据库中存在数据，返回1。
}

/*
文件筛选器：interactive
文件名：interactive_main.c
*/

#include <stdio.h>
#include "ui.h"
#include "data_manage.h"
#include "data_manage_p.h"

void user_choose(void)
{
	int temp;
	do {
		printf("\n");//换个行。
		direction_ui();//交互界面图形文件。
		printf("您的选择：");
		scanf("%d", &temp);
		switch (temp)//面条选择。
		{
		case 1: put_all(); break;//显示所有学生信息。
		case 2: display_find_data();break;//查找信息并显示。
		case 3: add_data(); break;//增加一个学生的信息。
		case 4: del_data(); break;//删除一个学生的信息。
		case 5: break;//退出。
		default: printf("请输入正确的操作命令！");
			break;
		}
	} while (temp!=5);

}
/*
文件筛选器：union_ui
文件名：ui_direction.c
*/

#include <stdio.h>
#include "ui.h"

void direction_ui(void)
{
	char *head = "ui_direction.txt";//交互界面的图形文件
	get_photo(head);//调用文件读取函数
}

/*
文件名：ui_head.c
*/

#include <stdio.h>
#include "ui.h"

void head_ui(void)
{
	char *head = "ui_head.txt"; //欢迎界面的文件名
	get_photo(head);//调用文件读取函数
}

/*
文件名：ui_tool.c
*/

#include <stdio.h>

void get_photo(char *file_name)
{
	FILE *fp;
	if ((fp = fopen(file_name, "r")) == NULL) {
		printf("error\n");//打开失败，提示错误
	}
	else {
		char ch;
		while ((ch = fgetc(fp)) != EOF)//不断读取下一个字符
		{
			putchar(ch);//以字符形式打印读取到的文件
		}
		fclose(fp);//文件关闭
	}
}

/*
Main.c
*/

#include "data_manage.h"
#include "data_get.h"
#include "ui.h"

int main(void)
{
	head_ui();//欢迎画面。
	
	initialize_data();//初始化程序，在内存中创建缓冲区。

	get_data();//获取文件中已存的学生数据，写入内存中以准备好的缓冲区。

	user_choose();//主控，与用户之间进行交互。

	save();//保存内存中学生数据，并将其存入文件。

	getchar();//防止文件闪现。
	getchar();
	return 0;
}

```