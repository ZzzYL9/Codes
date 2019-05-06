#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define N 10//点的个数 
#define m 8//边数 
#define max 200//区间范围 最大值 
#define min 0// 区间范围 最小值
#define Gmax 50//最大迭代次数 
#define K 1 //弹性系数
#define Defaultlength 50 // 
#define g Defaultlength*Defaultlength //斥力系数
#define f 10 //斥力常量
 
 
struct node{//二维坐标点 
	int num;//节点的序号 
	float x;
	float y;
};
struct edge{
	int v1;
	int v2;
	float naturelen;
};
struct edge e[m];//边 
struct node point[N];//N个点的坐标 

 
int degree[N];//顶点的度
float mass[N];//顶点的质量
float force[N];//顶点i所受的合力
float repulsion[N][N];// 顶点所受的斥力
float tension[N][N];// 顶点所受的张力
float sumforce;//系统合力 

void randinit(){
	int i;
	for(i=0;i<N;i++){
		point[i].num=i+1;
		point[i].x=(float)rand()/RAND_MAX*(max-min)+min;
		point[i].y=(float)rand()/RAND_MAX*(max-min)+min;
		force[i]=0;
	}
	for(i=0;i<N;i++){
		printf("%d %.2f %.2f\n",point[i].num,point[i].x,point[i].y);
	}
}
void saveinitfile(){//把点的坐标写入文件 
	int i;
	FILE *fp;
	fp=fopen("point0.txt","w");
	if(fp==NULL){
		return ;
	}
	for(i=0;i<N;i++){
		fprintf(fp,"%d %f %f\n",point[i].num,point[i].x,point[i].y);
	} 
	fclose(fp);
}
void savefile(){//把点的坐标写入文件 
	int i;
	FILE *fp;
	fp=fopen("point.txt","w");
	if(fp==NULL){
		return ;
	}
	for(i=0;i<N;i++){
		fprintf(fp,"%d %f %f\n",point[i].num,point[i].x,point[i].y);
	} 
	fclose(fp);
}
void readfile(){
	FILE *fp;
	fp=fopen("edge.txt","r");
	if(fp==NULL){
		return ;
	}
	int i;
	int w,r;
	
	i=0;
	while(fscanf(fp,"%d%d",&w,&r)!=EOF){
		e[i].v1=w;
		e[i].v2=r;
	//	printf("w:%d,r:%d,",w,r);
		e[i].naturelen=Defaultlength;
		i++;
		if(i>=m)break;
	}
	fclose(fp);
}
void computedegree(){//根据连接关系计算各个顶点的度 
	int i,j;
	for(i=0;i<N;i++){
		degree[i]=0;
	}
	for(i=0;i<m;i++){
	//	printf("e:%d,",e[i].v1-1);
		degree[e[i].v1-1]+=1;
		degree[e[i].v2-1]+=1;
	}
	
	for(i=0;i<N;i++){
		mass[i]=degree[i];
	//	printf("%d ,",degree[i]);
	}
	
	return ; 
}
void joinforce(){//计算系统合力sumforce 
	
} 
void computetension(){//计算张力 
	int i,j;
	float d;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			tension[i][j]=0;
		}
	}
	for(i=0;i<m;i++){
		d=(point[e[i].v1-1].x-point[e[i].v2-1].x)*(point[e[i].v1-1].x-point[e[i].v2-1].x)+(point[e[i].v1-1].y-point[e[i].v2-1].y)*(point[e[i].v1-1].y-point[e[i].v2-1].y);
		d=sqrt(d);
		if(d<=e[i].naturelen){
			tension[e[i].v1-1][e[i].v2-1]=0;
			tension[e[i].v2-1][e[i].v1-1]=0;
		}
		else{
			tension[e[i].v2-1][e[i].v1-1]=K*(d-e[i].naturelen);
			tension[e[i].v1-1][e[i].v2-1]=K*(d-e[i].naturelen);
		}
	}
} 
void computerepulsion(){//计算斥力 
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			repulsion[i][j]=0;
		}
	}
	float d;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i==j)continue;
			d=(point[i].x-point[j].x)*(point[i].x-point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y);
			if(d==0){
				repulsion[i][j]=f;
			}
			else {
				repulsion[i][j]=g*mass[i]*mass[j]/(d);
			}
		}
	}
}
int main(){
	srand(time(NULL));
	randinit();
	
	readfile();
	saveinitfile();
	computedegree();
	
	int k=0;
	int i,j; 
	while(k++<Gmax){
		
		computetension();
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				force[i]+=tension[i][j];
					point[i].x+=(point[j].x-point[i].x)*0.001*(tension[i][j]/mass[i]);
					point[i].y+=(point[j].y-point[i].y)*0.001*(tension[i][j]/mass[i]);
			}
		}	
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(i!=j){
					force[i]+=repulsion[i][j];
					point[i].x+=(point[i].x-point[j].x)*0.001*(repulsion[i][j]/mass[i]);
					point[i].y+=(point[i].y-point[j].y)*0.001*(repulsion[i][j]/mass[i]);
				}
			}
		}
		for(i=0;i<N;i++){
			force[i]=0;
		}
		printf("%d代：\n",k);
		for(i=0;i<N;i++){
			printf("%d %f %f\n",point[i].num,point[i].x,point[i].y);
		}
	}	
	savefile();
	 
	return 0;
}
