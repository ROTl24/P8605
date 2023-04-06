#include <string.h>
#include <iostream>
#define MAXN 10010
#define MAXM 100010
using namespace std;
int d[MAXN], u[MAXM], v[MAXM];
//d记录边的数量，u记录节点数量，v终点数量ssr 
int main() {
	int n, i, m;
	long long ans = 0;
	scanf("%d%d", &n, &m);
	memset(d, 0, sizeof(d));
	for (i = 0; i < m; i++) {
		scanf("%d%d", &u[i], &v[i]);//记录数字位置 
		d[u[i]]++;
		d[v[i]]++;
	}
	for (i = 0; i < m; i++) {
		if (d[u[i]] > 1 && d[v[i]] > 1)
			//如果d[u[i]]>1且d[v[i]]>1，就说明节点u[i]和节点v[i]至少各有两条与其相连的边，也就是说它们可以作为路径的中间节点，连接其他的边
			ans += (d[u[i]] - 1) * (d[v[i]] - 1) * 2;
		//减1的原因是要去掉节点u[i]和节点v[i]这两个端点，因为它们已经在边的两端出现过了。
		//乘2的原因是路径可以从u[i]到v[i]，也可以从v[i]到u[i]，因此需要将这两种情况都计算进去。
	}
	cout << ans;
	return 0;
}