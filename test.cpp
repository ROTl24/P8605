#include <string.h>
#include <iostream>
#define MAXN 10010
#define MAXM 100010
using namespace std;
int d[MAXN], u[MAXM], v[MAXM];
//d��¼�ߵ�������u��¼�ڵ�������v�յ�����ssr 
int main() {
	int n, i, m;
	long long ans = 0;
	scanf("%d%d", &n, &m);
	memset(d, 0, sizeof(d));
	for (i = 0; i < m; i++) {
		scanf("%d%d", &u[i], &v[i]);//��¼����λ�� 
		d[u[i]]++;
		d[v[i]]++;
	}
	for (i = 0; i < m; i++) {
		if (d[u[i]] > 1 && d[v[i]] > 1)
			//���d[u[i]]>1��d[v[i]]>1����˵���ڵ�u[i]�ͽڵ�v[i]���ٸ����������������ıߣ�Ҳ����˵���ǿ�����Ϊ·�����м�ڵ㣬���������ı�
			ans += (d[u[i]] - 1) * (d[v[i]] - 1) * 2;
		//��1��ԭ����Ҫȥ���ڵ�u[i]�ͽڵ�v[i]�������˵㣬��Ϊ�����Ѿ��ڱߵ����˳��ֹ��ˡ�
		//��2��ԭ����·�����Դ�u[i]��v[i]��Ҳ���Դ�v[i]��u[i]�������Ҫ������������������ȥ��
	}
	cout << ans;
	return 0;
}