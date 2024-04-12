//BFS
// structions:和DFS本质上都是递归
int BFS(Node start, Node target) {
    Queue<Node> q; // 核心数据结
    q.push(start); // 将起点加入队列
    int step = 0; // 记录扩散的步数

    while (q!=empty) {
        int sz = q.size();
        /* 将当前队列中的所有节点向四周扩散 */
        for (int i = 0; i < sz; i++) {
            Node cur = q.poll();
            /* 划重点：这里判断是否到达终点 */
            if (cur is target)
                return step;
            /* 将 cur 的相邻节点加入队列 */
            for (Node x : cur.adj()) {
                if (x not in visited) {
                    q.offer(x);
                    visited.add(x);
                }
            }
        }
        /* 划重点：更新步数在这里 */
        step++;
    }
}

// example 1:给定一个二叉树，找出其最小深度。
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
// 说明：叶子节点是指没有子节点的节点。

// 普通递归做法
#include <iostream>
#include <queue>
using namespace std;
int minDepth(TreeNode* root) {
  if(root==nullptr) return 0;
  if(root->left==nullptr) return minDepth(root->right)+1;
  if(root->right==nullptr) return minDepth(root->left)+1;
  return min(minDepth(root->left),minDepth(root->right))+1;
}

// BFS做法
#......
int minDepth(TreeNode* root) {
    if(root==nullptr) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int depth=1;
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            TreeNode* cur=q.front();
            q.pop();
            if(cur->left==nullptr&&cur->right==nullptr){
                return depth;
            }
            if(cur->left!=nullptr){
                q.push(cur->left);
            }
            if(cur->right!=nullptr){
                q.push(cur->right);
            }
        }
        depth++;
    }
    return depth;
}

// example 2 求矩阵距离
// https://www.acwing.com/problem/content/description/3086/
// 给定一个 n×m的 01矩阵，定义 aij与 akl 之间的距离为 D(aij,akl)=|i−k|+|j−l|
// 对于每个元素 aij，请求出与它距离最近且值为 1的元素 akl和它的距离是多少。
// 当元素 aij本身就为 1时，与它距离最近且值为 1 的元素就是它自己，距离为 0
// in
// 3 4
// 0001
// 0011
// 0110
// out
// 3 2 1 0
// 2 1 0 0
// 1 0 0 1

// BFS
#include <bits/stdc++.h>
using namespace std;
int n, m, mapp[1010][1010], res[1010][1010];
queue<pair<int, int>> q;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mapp[nx][ny] != 1 && res[nx][ny] == 0) {
                res[nx][ny] = res[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string a;
        cin >> a;
        for (int j = 1; j <= m; j++) {
            mapp[i][j] = a[j - 1] - '0';
            if (mapp[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    bfs();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// example3 给出树的后序中序排列，输出其层序排列
// 递归，BFS
// in 7
// 2 3 1 5 7 6 4
// 1 2 3 4 5 6 7
// out 4 1 6 3 5 7 2

#include <iostream>
#include <queue>
using namespace std;

int n,backxu[35],midxu[35],pos[35],l[35],r[35];

int build(int bl,int br,int ml,int mr,int level){
    if(bl>br){
        return 0;
    }
    int val=backxu[br];
    
    int k=pos[val];
    l[val]=build(bl,k-ml+bl-1,ml,k-1,level+1);
    r[val]=build(k-ml+bl,br-1,k+1,mr,level+1);
    return val;
}

void bfs(){
    queue<int> q;
    q.push(backxu[n-1]);
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        if(l[temp]!=0){
            q.push(l[temp]);
        }
        if(r[temp]!=0){
            q.push(r[temp]);
        }
    }
    
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>backxu[i];
    }
    for(int i=0;i<n;i++){
        cin>>midxu[i];
    }
    for(int i=0;i<n;i++){
        pos[midxu[i]]=i;
    }
    build(0,n-1,0,n-1,0);
    bfs();
    return 0;
}
