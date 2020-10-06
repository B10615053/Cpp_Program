#include <iostream>
#include<fstream>
#define N 9
using namespace std;
#pragma region 變數宣告
//檔案名字
const std::string FILE_NAME = "Question.txt";
//輸出
void print(char a[N][N]);
//讀取檔案
void readfile();
//遞迴解數獨 rightNownum表示跑了幾次
bool Recurcive(int rightNowNum);
//輸入是不合法 先預設他合法
bool notileagle = false;
//開儲存那些字是我用過的陣列
int row[9][10], column[9][10], lattice[9][10];
char a[N][N] = { 'n','n','n','n','n','n','n','n','n',
				 'n','n','n','n','n','n','n','n','n',
				 'n','n','n','n','n','n','n','n','n',
				 'n','n','n','n','n','n','n','n','n',
				 'n','n','n','n','n','n','n','n','n',
				 'n','n','n','n','n','n','n','n','n',
				 'n','n','n','n','n','n','n','n','n',
				 'n','n','n','n','n','n','n','n','n',
				 'n','n','n','n','n','n','n','n','n' };
#pragma endregion

#pragma region 主程式 main
int main()
{
	//讀取檔案
	readfile();
	//假設不合法輸入直接輸出 下面不做
	if (notileagle) cout << "the input Sudoku is illegal" << endl;
	else {
		//遞迴找尋答案(先給0<-表示從0開始做) 回傳0值代表沒找到答案
		if(!Recurcive(0))cout << "no soultion" << endl;
	}
	system("pause");
	return 0;
}
#pragma endregion

#pragma region 印出矩陣
void print(char a[N][N])
{
	for (int i = 0; i < N; i++)
	{
		printf(" ---------  ---------  ---------\n");
		if (i == 3 || i == 6)
			printf(" ---------  ---------  ---------\n");

		for (int j = 0; j < N; j++)
		{
			if (j == 3 || j == 6)
				printf("｜");
			printf("｜%c", a[i][j]);
		}
		printf("｜\n");
	}
	printf(" ---------  ---------  ---------\n");
}
#pragma endregion

#pragma region 輸入檔案
void readfile() {
	//下面先把我所有的row column lattice數字都先沒有 所以是0
	memset(row, 0, sizeof(row));
	memset(column, 0, sizeof(column));
	memset(lattice, 0, sizeof(lattice));
	fstream readfile;
	readfile.open(FILE_NAME, ios::in);
	char n;
	//y 軸 跟 x軸宣告 (照正常數學座標)
	int y = 0, x = 0;
	while (readfile >> n)
	{
		//輸入進我的a陣列
		a[y][x] = n;
		if (n!= 'n') {
			//看那些數字用過(分成row column 跟 lattice) ,但首先會判斷他在這row column lattice有沒有先用到 假設為1 代表不合法輸入
			if (row[y][a[y][x] - 48] == 1) { notileagle = true; break; }
			else row[y][a[y][x] - 48] = 1;
			if (column[x][a[y][x] - 48] == 1){ notileagle = true; break; }
			else column[x][a[y][x] - 48] = 1;
			if(lattice[(y / 3) * 3 + x / 3][a[y][x] - 48] == 1){ notileagle = true; break; }
			else lattice[(y / 3) * 3 + x / 3][a[y][x] - 48] = 1;
		}
		else{
			//為要找得答案 所以把他們都設為0 且都用過
			row[y][0] = 1;
			column[x][0] = 1;
			lattice[(y / 3) * 3 + x / 3][0] =1;
		}
#pragma region 每讀取一次x前移一格
		x = x + 1;
		if (x >= 9) {
			x = 0;
			y += 1;
		}
#pragma endregion
	}
	readfile.close();
}
#pragma endregion

#pragma region Dfs
bool Recurcive(int rightNowNum)
{
	//當我的值跑到81代表我都找到了 並且輸出解
	if (rightNowNum == N*N) {
		//輸出
		print(a);
		//然後return 1表示找到解了 
		return 1;
	}
	//y軸跟x軸值
	int y = rightNowNum / N, x = rightNowNum%N;
	//假設這格是有數字 就可以直接往下一個遞迴
	if (a[y][x] != 'n') {
		//遞迴 並且值往下加1 (並且判斷這個值是否ok)
		if (Recurcive(rightNowNum + 1)) return 1;
	}
	else if(a[y][x]=='n')
	{
		//從數字1到9
		for (int i = 1; i <= N; i++)
		{
			//判斷在row column lattice 是否被使用過 有用過的數字就不能再填 
			if (row[y][i] == 0 && column[x][i] == 0 && lattice[(y / 3) * 3 + x / 3][i] == 0) {
				//把他們都設成用過
				row[y][i] = 1;
				column[x][i] = 1;
				lattice[(y / 3) * 3 + x / 3][i] = 1;
				a[y][x] = i + 48;
				//遞迴 並且值往下加1 (並且判斷這個值是否ok)
				if (Recurcive(rightNowNum + 1))  return 1; 
				a[y][x] = 'n';
				//代表是錯誤答案 遞迴回來後把他們都設定成沒用過
				row[y][i] = 0;
				column[x][i] = 0;
				lattice[(y / 3) * 3 + x / 3][i] = 0;
			}
		}
		
	}
	//沒有找到解 回傳0
	return 0;
}
#pragma endregion


