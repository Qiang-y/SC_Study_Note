# Trie Tree
概念：字典树（TrieTree），是一种树形结构，典型应用是用于统计，排序和保存大量的字符串（但不仅限于字符串,如01字典树）。主要思想是利用字符串的公共前缀来节约存储空间。很好地利用了串的公共前缀，节约了存储空间。字典树主要包含两种操作，插入和查找。
## 字典树代码实现方法
### 通过二维数组实现
在用代码实现字典树时，我们主要需要实现两种操作：即录入单词和查找单词.
1.我们用一个二维数组来实现字典树的建树。先把代码写出来，之后再解释。
`const int N = 1000050;   

int trie[N][26];    

int cnt[N];

int id;//id代表字典树中每一个节点的编号，id的大小只与插入字典树的先后顺序有关 

void insert(string s)

{

        int p = 0;
        
        for (int i = 0; i < s.size(); i++)
        
        {
        
                int x = s[i] - 'a';
                
                if (trie[p][x] == 0) trie[p][x] = ++id;
                
                p = trie[p][x];
                
        }
        
        cnt[p]++;
        
}

int  find(string s)

{

        int p = 0;
        
        for (int i = 0; i < s.size(); i++)
        
        {
        
                int x = s[i] - 'a';
                
                if (trie[p][x] == 0)return 0;
                
                p = trie[p][x];
                
        }
        
        return cnt[p];
        
}`

trie[N][26] ： 每个trie代表一条边，字典树其中1\~N为边上方节点的编号，0代表root节点，1\~26为连在i节点下方的26个字母。如果trie[i][x]=0,则代表字典树中目前没有这个点，而trie[i][x]的值代表这个点下方连有的点的编号，例如：trie[i][2]=9代表第i号点和的下方连有一个点‘c’，并且那个点的编号是9，为什么是c呢？因为 ‘c’-‘a’=2
cnt[N]: cnt[i]==0代表编号为i的点不是一个单词的结束点，在上面的图中代表这个点不是空点，但是没有标红，cnt[i]！=0代表编号为i的点是一个单词的结束点，即红点。cnt[i]不一定只为0或1，因为有可能多次输入了同一个单词。

p代表查询与插入时的不断变化的当前节点编号，初始化为0，代表初始节点，在函数的循环中，我们首先用x确定接下来要找的字母，再通过变量x确定了接下来我们需要查找当前节点下是否有连接着目标字母的节点。通过每次确定的x，我们通过trie[p][x] 查找连着目标字母的节点的编号，如果目标节点存在，就把p更新成目标节点的编号（p = trie[p][x]）。而如果trie[p][x] == 0，代表字典树中没有这个点，如果是查找就代表没有这个单词，查找失败。而如果是插入函数，我们就用 ++id 来把这个点存进字典树。我们在两个函数的最后用cnt[p]来涂红节点或返回节点值。

原文链接：https://blog.csdn.net/qq_49688477/article/details/118879270

###通过指针数组实现

leetcode:208 实现Trie树（前缀树）

`class Trie {

private:

    vector<Trie*> children;//通过动态数组对每个节点的位置进行存储
    
    bool isEnd;//判断该节点是否为一个单词的结束处
    
    Trie* searchPrefix(string prefix) {
    
        Trie* node = this;
        
        for (char ch : prefix) {
        
            ch -= 'a';
            
            if (node->children[ch] == nullptr) {
            
                return nullptr;
                
            }
            
            node = node->children[ch];
            
        }
        
        return node;
        
    }

public:

    Trie() : children(26), isEnd(false) {}
    
    void insert(string word) {
    
        Trie* node = this;
        
        for (char ch : word) {
        
            ch -= 'a';
            
            if (node->children[ch] == nullptr) {
            
                node->children[ch] = new Trie();
                
            }
            
            node = node->children[ch];
            
        }
        
        node->isEnd = true;
        
    }
    
    bool search(string word) {
    
        Trie* node = this->searchPrefix(word);
        
        return node != nullptr && node->isEnd;
        
    }
    
    bool startsWith(string prefix) {
    
        return this->searchPrefix(prefix) != nullptr;
        
    }
    
};`

作者：力扣官方题解

链接：https://leetcode.cn/problems/implement-trie-prefix-tree/solutions/717239/shi-xian-trie-qian-zhui-shu-by-leetcode-ti500/
