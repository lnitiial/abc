#include <iostream>
using namespace std;

int main(int argc,const char* argv[])
{
	FILE* frp = fopen("hotel.txt","r");
	if(NULL == frp)
	{
		perror("frp");
		return 0;
	}
	int num = -1;
	int cnt = -1;
	int ret = fscanf(frp,"%d\n",&num);
	cout << ret << endl;
	cout << num << endl;
	ret = fscanf(frp,"%d\n",&cnt);
	cout << cnt << endl;

	fclose(frp);
}
