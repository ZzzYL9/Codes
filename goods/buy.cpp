#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using std::istream;

char id[20] = "test"; //账号
char pd[30] = "root"; //密码
char quit[20] = "quit"; //退出

int Ordernum;//订购数量
int j;
int r = 0;//用于比较的全局变量
int Last;//订购后剩余的库存
char address[41];//订购地址

#define N 100

//登录
typedef struct{
    char ID[20];//用户名
    char passwd[30];//密码
}user_inf;

//商品信息
struct goods{
    int goods_num;//商品编号
    char goods_name[50];//商品名称
    char company[20];//公司名称
    char goods_type[20];//商品型号
    double goods_prices;//商品价格
    char goods_places[20];//商品产地
    int left_num;//库存数量
    char left_places[20];//仓库地址
    int goods_ordered;//已订购数量
} goods_inf[N];

//商品订购信息
struct order{
    int goods_num; //商品编号
    char goods_name[50];//商品名称
    char company[20];//公司名称
    char goods_type[20];//商品型号
    double goods_prices;//商品价格
    char goods_places[20];//商品产地
    char left_places[20];//仓库地址
    int goods_ordered;//已订购数量
    char address[20];//地址
}ordered[N];


void login(void);
void menu_main(void);
void buy_file(void);
void menu_main(void);
void search_goods(void);
void search_name(void);
void search_type(void);
void search_ID(void);
void addaddress(void);
void outputall(void);
void buy_goods(void);
void add(void);
void del(void);
void change(void);
void write_order_inf(void);
void outputall_onlyput(void);
void choice(void);
void choice_price(void);
void choice_place(void);

istream& read(istream& is);
int main()
{
    std::ifstream ifs{"../goods/goods_inf.txt"}; //申请可以从文件中读取数据的流
    read(ifs);
    printf("****商品订购系统****\n\n");
    printf("请先登录\n");
    login();
   return 0;
}

void login()
{
    user_inf users;
    memset(users.ID, 0, sizeof(char)*20);
    printf("请输入用户名:\n");
    scanf("%s", users.ID);
    memset(users.passwd, 0, sizeof(char)*30);
    printf("请输入密码:\n");
    scanf("%s", users.passwd);
    if(strcmp(users.ID, id)==0 && strcmp(users.passwd, pd)==0){
        menu_main();
    }
    else
        printf("密码或者用户名错误\n");
}

void menu_main(){
    int n;
    printf("\n\n");
    printf("1.查询商品信息\n");
    printf("2.增加商品信息\n");
    printf("3.删除商品信息\n");
    printf("4.修改商品信息\n");
    printf("5.列出所有商品信息\n");
    printf("6.商品选择\n");
    printf("\n");
    scanf("%d", &n);

    switch (n) {
    case 1:search_goods();
        break;
    case 2:add();
        break;
    case 3:del();
        break;
    case 4:change();
        break;
    case 5:outputall();
        break;
    case 6:choice();
        break;
    }

}

istream& read(istream& is)
{

    while(!is.eof()){
        r++;
        is >> goods_inf[r].goods_num >> goods_inf[r].goods_name >> goods_inf[r].company
                >> goods_inf[r].goods_type >> goods_inf[r].goods_prices >> goods_inf[r].goods_places
                    >> goods_inf[r].left_num >> goods_inf[r].left_places >> goods_inf[r].goods_ordered;

    }

}


//查询商品
void search_goods()
{
    int num;
    printf("按商品名称查询请按 1\n按商品型号查询请按 2\n按商品编号查询请按 3\n");
    scanf("%d", &num);

    switch (num) {
    case 1:search_name();
        break;
    case 2:search_type();
        break;
    case 3:search_ID();
        break;
    }
}

//根据商品名称查询
void search_name()
{
    int i, k = 0;
    char str[24], c3[4];

    printf("\n请输入你要查找的名称:");
    scanf("%s", str);
    printf("\n您所查找的%s\n", str);
    for(i = 0; i < r; i++){
        k = strcmp(goods_inf[i].goods_name, str);
        if(k == 0){
            printf("%4d %-10s %-5s %-12s %9.2f %-10s %5d %-10s %4d\n", goods_inf[i].goods_num, goods_inf[i].goods_name, goods_inf[i].company, goods_inf[i].goods_type, goods_inf[i].goods_prices, goods_inf[i].goods_places, goods_inf[i].left_num, goods_inf[i].left_places, goods_inf[i].goods_ordered);//商品编号 商品名称 公司名称 商品型号 商品价格 商品产地 库存数量 仓库地址 已订购数量
        }
    }

        printf("请按任意键选购,取消或产品不存在按quit\n");
        scanf("%s", c3);
        if(strcmp(c3,quit) == 0){
            printf("\n");
            menu_main();
        }
        else
            buy_goods();
}

//根据商品类型查询
void search_type()
{
    char type[50];

    printf("请输入要查询的型号:\n");
    scanf("%s", type);

    for(int i = 0; i < r; i++){
        if(strcmp(goods_inf[i].goods_type, type) == 0){
            printf("%4d %-10s %-5s %-12s %9.2f %-10s %5d %-10s %4d\n", goods_inf[i].goods_num, goods_inf[i].goods_name, goods_inf[i].company, goods_inf[i].goods_type, goods_inf[i].goods_prices, goods_inf[i].goods_places, goods_inf[i].left_num, goods_inf[i].left_places, goods_inf[i].goods_ordered);//商品编号 商品名称 公司名称 商品型号 商品价格 商品产地 库存数量 仓库地址 已订购数量
        }
    }

        printf("请按任意键选购,取消或产品不存在按quit: \n");
        char c3[4];
        scanf("%s", c3);
        if(strcmp(c3,quit) == 0){
            printf("\n");
            menu_main();
        }
        else
            buy_goods();
}

//根据商品编号查询
void search_ID()
{
    int i;
    int a;//输入编号

    printf("请输入要查询的编号: \n");
    scanf("%d", &a);
    printf("您要查询的是%d\n", a);
    for(i = 0; i < r; i++){

        if(goods_inf[i].goods_num == a){
            printf("%4d %-10s %-5s %-12s %9.2f %-10s %5d %-10s %4d\n", goods_inf[i].goods_num, goods_inf[i].goods_name, goods_inf[i].company, goods_inf[i].goods_type, goods_inf[i].goods_prices, goods_inf[i].goods_places, goods_inf[i].left_num, goods_inf[i].left_places, goods_inf[i].goods_ordered);//商品编号 商品名称 公司名称 商品型号 商品价格 商品产地 库存数量 仓库地址 已订购数量
        }
    }

        printf("请按任意键选购,取消或产品不存在按quit: \n");

        char c3[4];
        scanf("%s", c3);
        if(strcmp(c3,quit) == 0){
            printf("\n");
            menu_main();
        }
        else
            buy_goods();
}

//订购
void buy_goods(){
    int i;
    int a;
    char ch;

    outputall_onlyput();
    printf("\n请输入您想订购的商品编号:(取消请按quit)\n");
    scanf("%d", &a);
    for(i = 0; i < r; i++){
        if(goods_inf[i].goods_num == a){
            printf("\n");
            printf("%4d %-10s %-5s %-12s %9.2f %-10s %5d %-10s %4d\n", goods_inf[i].goods_num, goods_inf[i].goods_name, goods_inf[i].company, goods_inf[i].goods_type, goods_inf[i].goods_prices, goods_inf[i].goods_places, goods_inf[i].left_num, goods_inf[i].left_places, goods_inf[i].goods_ordered);//商品编号 商品名称 公司名称 商品型号 商品价格 商品产地 库存数量 仓库地址 已订购数量
            Ordernum = i;
            j = i;
            break;
        }
    }

    Last = goods_inf[j].left_num - goods_inf[j].goods_ordered;
    if(Last != 0){
        printf("还剩余%d件, 请输入您的订购数量:\n", Last);
        scanf("%d", &ordered[j].goods_ordered);
        if(ordered[j].goods_ordered >= 0 && ordered[j].goods_ordered <= (goods_inf[Ordernum].left_num - goods_inf[Ordernum].goods_ordered)){
            addaddress();
            printf("发货地址是%s\n",goods_inf[j].left_places);
            menu_main();
        }
        else{
            printf("您填写的数量有误, 请重新购买\n");
            menu_main();
        }
    }
}

//添加地址函数
void addaddress()
{
    char ch[4];
    printf("请输入您的地址: \n");
    scanf("%s", address);
    printf("您的地址是: %s\n\n", address);
    printf("确认请按任意键,重新输入请按quit\n");

    scanf("%s", ch);
    printf("\n");
    if(strcmp(ch,quit) != 0)
        printf("您已经成功订购!\n");
    write_order_inf();
//    menu_main();
}

//添加商品信息
void add()
{
    int i;

    printf("请输入添加的商品信息: \n");
    printf("商品编号 商品名称 公司名称 商品型号 商品价格 商品产地 库存数量 仓库地址 已订购数量\n");
    scanf("%d %s %s %s %lf %s %d %s %d",&goods_inf[r].goods_num, goods_inf[r].goods_name, goods_inf[r].company, goods_inf[r].goods_type, &goods_inf[r].goods_prices, goods_inf[r].goods_places, &goods_inf[r].left_num, goods_inf[r].left_places, &goods_inf[r].goods_ordered);
    std::ofstream ofs_add{"../goods/goods_inf.txt", std::ios::app};

        ofs_add << goods_inf[r].goods_num << " " << goods_inf[r].goods_name << " " << goods_inf[r].company
            << " " << goods_inf[r].goods_type << " " << goods_inf[r].goods_prices << " " << goods_inf[r].goods_places
                << " " << goods_inf[r].left_num << " " << goods_inf[r].left_places << " " << goods_inf[r].goods_ordered << "\n";
        r++;
    ofs_add.close();

    printf("商品添加成功!\n");

    menu_main();
}

//删除商品信息
void del()
{
    int i, j;

    std::ofstream ofs_clear{"../goods/goods_inf.txt", std::ios::trunc};

    printf("请输入删除的商品编号:\n");
    scanf("%d", &j);
    for(i = 0; i < r; i++){
        if(goods_inf[i].goods_num == j){
            goods_inf[i].goods_num = 0;
        }
    }
    std::ofstream ofs_change{"../goods/goods_inf.txt", std::ios::app};

    for(i = 0; i < r; i++){
        if(goods_inf[i].goods_num != 0){
            ofs_clear << goods_inf[i].goods_num << " " << goods_inf[i].goods_name << " " << goods_inf[i].company
                                                   << " " << goods_inf[i].goods_type << " " << goods_inf[i].goods_prices << " " << goods_inf[i].goods_places
                                                       << " " << goods_inf[i].left_num << " " << goods_inf[i].left_places << " " << goods_inf[i].goods_ordered << "\n";
        }
    }
    ofs_clear.close();

    printf("商品删除成功!\n");
    menu_main();
}

//修改商品信息
void change()
{
    char ch;
    char company[20], type[100];
    int i, j, price, save, sell;
    printf("请输入要修改的商品编号:\n");
    scanf("%d", &j);
    for(i = 0; i < r; i++){
        if(goods_inf[i].goods_num == j){
            printf("商品编号:%d\n商品名称:%s\n公司名称:%s\n商品单价:%f\n商品型号:%s\n库存数量:%d\n已订购数量:%d\n",goods_inf[i].goods_num, goods_inf[i].goods_name, goods_inf[i].company, goods_inf[i].goods_prices, goods_inf[i].goods_type, goods_inf[i].left_num, goods_inf[i].goods_ordered);
            printf("请输入您想修改的哪条信息:\n1.公司名称 2.商品单价 3.商品型号 4.库存数量 5.已订购数量\n");
            getchar();
            scanf("%c", &ch);
            switch (ch) {
            case '1':printf("请输入商品生产商:");
                scanf("%s", company);
                strcpy(goods_inf[i].company, company);
                break;
            case '2':printf("请输入商品单价:");
                scanf("%f", &price);
                goods_inf[i].goods_prices = price;
                break;
            case '3':printf("请输入商品型号:");
                getchar();
                scanf("%s", type);
                strcpy(goods_inf[i].goods_type, type);
                break;
            case '4':printf("请输入商品库存:");
                getchar();
                scanf("%d", &save);
                goods_inf[i].left_num = save;
                break;
            case '5':printf("请输入商品已订购数量:");
                scanf("%d", &sell);
                goods_inf[i].goods_ordered = sell;
                break;
            }
        }
    }

    std::ofstream ofs_clear{"../goods/goods_inf.txt", std::ios::trunc};
    for(i = 0; i < r; i++){
        if(goods_inf[i].goods_num != 0){
            ofs_clear << goods_inf[i].goods_num << " " << goods_inf[i].goods_name << " " << goods_inf[i].company
                << " " << goods_inf[i].goods_type << " " << goods_inf[i].goods_prices << " " << goods_inf[i].goods_places
                    << " " << goods_inf[i].left_num << " " << goods_inf[i].left_places << " " << goods_inf[i].goods_ordered << "\n";
        }
    }
    ofs_clear.close();
    printf("商品修改成功!\n");
    menu_main();
}

//按价格选择
void choice_price()
{
    int i;
    double min, max;
    printf("您想选择什么价格区间(例如:20.00 60.00):\n");
    scanf("%lf %lf", &min, &max);
    printf("这是符合您预估的商品: \n");
    for(i = 0; i < r; i++){
        if(goods_inf[i].goods_prices >= min && goods_inf[i].goods_prices <= max){
            printf("%4d %-10s %-5s %-12s %9.2f %-10s %5d %-10s %4d\n", goods_inf[i].goods_num, goods_inf[i].goods_name, goods_inf[i].company, goods_inf[i].goods_type, goods_inf[i].goods_prices, goods_inf[i].goods_places, goods_inf[i].left_num, goods_inf[i].left_places, goods_inf[i].goods_ordered);//商品编号 商品名称 公司名称 商品型号 商品价格 商品产地 库存数量 仓库地址 已订购数量
            r++;
        }
    }

    if(r!=0){
        printf("请按任意键选购,取消按quit: \n");

        char c3[4];
        scanf("%s", c3);
        if(strcmp(c3,quit) == 0){
            printf("\n");
            menu_main();
        }
        else
            buy_goods();
    }
}

//按产地选择
void choice_place()
{
    int i;
    char place[100];
    printf("您想选择什么产地的商品:\n");
    scanf("%s", place);
    printf("这是符合您预估的商品: \n");
    for(i = 0; i < r; i++){
        if(strcmp(goods_inf[i].goods_places, place) == 0){
            printf("%4d %-10s %-5s %-12s %9.2f %-10s %5d %-10s %4d\n", goods_inf[i].goods_num, goods_inf[i].goods_name, goods_inf[i].company, goods_inf[i].goods_type, goods_inf[i].goods_prices, goods_inf[i].goods_places, goods_inf[i].left_num, goods_inf[i].left_places, goods_inf[i].goods_ordered);//商品编号 商品名称 公司名称 商品型号 商品价格 商品产地 库存数量 仓库地址 已订购数量

        }
    }

    if(r!=0){
        printf("请按任意键选购,取消按quit: \n");

        char c3[4];
        scanf("%s", c3);
        if(strcmp(c3,quit) == 0){
            printf("\n");
            menu_main();
        }
        else
            buy_goods();
    }

}

void choice()
{
    int n;
    printf("您想根据什么选择方案:\n");
    printf("1.根据型号 2.根据价格 3.根据产地\n");
    scanf("%d", &n);
    switch (n) {
    case 1:search_type();
        break;
    case 2:choice_price();
        break;
    case 3:choice_place();
        break;
    }
}

//输出所有信息
void outputall_onlyput()
{
    int i;
    for(i = 0; i < r; i++){
        if(goods_inf[i].goods_num != 0){
            printf("%4d %-10s %-5s %-12s %9.2f %-10s %5d %-10s %4d\n", goods_inf[i].goods_num, goods_inf[i].goods_name, goods_inf[i].company, goods_inf[i].goods_type, goods_inf[i].goods_prices, goods_inf[i].goods_places, goods_inf[i].left_num, goods_inf[i].left_places, goods_inf[i].goods_ordered);//商品编号 商品名称 公司名称 商品型号 商品价格 商品产地 库存数量 仓库地址 已订购数量
        }
    }
}

//输出所有信息并选购
void outputall()
{
    int i;
    for(i = 0; i < r; i++){
        if(goods_inf[i].goods_num != 0){
            printf("%4d %-10s %-5s %-12s %9.2f %-10s %5d %-10s %4d\n", goods_inf[i].goods_num, goods_inf[i].goods_name, goods_inf[i].company, goods_inf[i].goods_type, goods_inf[i].goods_prices, goods_inf[i].goods_places, goods_inf[i].left_num, goods_inf[i].left_places, goods_inf[i].goods_ordered);//商品编号 商品名称 公司名称 商品型号 商品价格 商品产地 库存数量 仓库地址 已订购数量
        }
    }

    char c3[4];
    if(r!=0){
        printf("请按任意键选购,取消或产品不存在按quit\n");
        scanf("%s", c3);
        if(strcmp(c3,quit) == 0){
            printf("\n");
            menu_main();
        }
        else
            buy_goods();
    }
}

//写入订购信息
void write_order_inf()
{
    std::ofstream ofs{"../goods/order_inf.txt", std::ios::app}; //申请可以写到文件中的流
    ordered[Ordernum].goods_ordered = goods_inf[j].goods_ordered;
    strcpy(ordered[Ordernum].goods_name, goods_inf[j].goods_name);
    strcpy(ordered[Ordernum].company, goods_inf[j].company);
    strcpy(ordered[Ordernum].goods_type, goods_inf[j].goods_type);
    ordered[Ordernum].goods_prices = goods_inf[j].goods_prices;

    ofs << goods_inf[Ordernum].goods_num << " " << goods_inf[Ordernum].goods_name << " " << goods_inf[Ordernum].company
        << " " << goods_inf[Ordernum].goods_type << " " << goods_inf[Ordernum].goods_prices << " " << goods_inf[Ordernum].goods_places
            << " " << goods_inf[Ordernum].left_num << " " << goods_inf[Ordernum].left_places << " " << goods_inf[Ordernum].goods_ordered << "\n";
    ofs.close();

    Ordernum++;
}
