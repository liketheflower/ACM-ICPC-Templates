typedef int weight_t;
const int N = 1005;
int pre[N];
bool vis[N];
weight_t dis[N], g[N][N];
void init(int n, int m, int s)
{
    memset(pre, 0, sizeof(pre));
    memset(vis, false, sizeof(vis));
    for (int i = 0; i <= n; i++)
    {
        dis[i] = inf;
    }
    dis[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            g[i][j] = inf;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, l;
        scanf("%d%d%d", &u, &v, &l);
        //l = min(l, g[u][v]);
        g[u][v] = l;
        g[v][u] = l;
    }
}

void Dijkstra(int n)
{
    for (int i = 1; i <= n; i++)
    {
        //̰��, ������Ȩֵ��С�ĵ���±�
        int u = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dis[j] < dis[u])
                u = j;
        }
        vis[u] = true;
        for (int j = 1; j <= n; j++)
        {
            if (g[u][j] != inf && !vis[j] && dis[u] + g[u][j] < dis[j])
            {
                dis[j] = dis[u] + g[u][j];
                pre[j] = u;
            }
        }
    }
}

void Print(int s, int v)
{
    //��˳�������
    stack<int> path;
	if (pre[v])
    {
        while (v != s)
        {
            path.push(v);
            v = pre[v];
        }
        path.push(v);
    }
    else path.push(-1); //���û��·��
    while (!path.empty())
    {
        printf("%d ", path.top());
        path.pop();
    }
	printf("\n");
}