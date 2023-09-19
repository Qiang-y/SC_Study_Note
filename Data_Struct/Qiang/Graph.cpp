#include<iostream>
#include<vector>
using namespace std;

typedef struct {
	int coast;
	int pre;
}NodeCoast;
class Node{
public:
	int val;
	Node* child;
	Node* nextbro;
public:
	Node(){
		child = NULL;
		nextbro = NULL;
	}
	Node(int val_) {
		val = val_;
		child = nextbro = NULL;
	}
};
//Node* Root = NULL;
void printTree(Node* Root) {
	if (Root == NULL) {
		cout << "no tree " << endl;
		return;
	}
	Node* firstChild = Root, *allBro = Root;
	while (firstChild != NULL) {
		allBro = firstChild;
		while (allBro != NULL) {
			cout << allBro->val << "--";
			allBro = allBro->nextbro;
		}
		cout << "| " << endl;
		firstChild = firstChild->child;
	}
}
Node* searchNode(Node* Root, int val_) {
	Node* temp = Root;
	while (temp != NULL) {
		Node* temp2 = temp;
		while (temp2 != NULL) {
			if (temp2->val == val_)	return temp2;
			temp2 = temp2->nextbro;
		}
		temp = temp->child;
	}
	return NULL;
}

class Graph{
public:
	vector<int> Point;
	vector<vector<int>> Edge;
public:
	Graph() = default;
	Graph(int pointNum, vector<vector<int>> &edge){
		vector<int> row(pointNum);
		for(int i = 0; i < pointNum; i++){
			Point.push_back(1);
			Edge.push_back(row);
		}
		for(int i = 0 ; i < edge.size(); i++){
			Edge[edge[i][0]][edge[i][1]] = 1;
			Edge[edge[i][1]][edge[i][0]] = 1;
		}

	}
	Graph(int pointNum, vector<vector<int>>& edge, int val) {
		vector<int> row(pointNum);
		for (int i = 0; i < pointNum; i++) {
			Point.push_back(1);
			Edge.push_back(row);
		}
		for (int i = 0; i < edge.size(); i++) {
			Edge[edge[i][0]][edge[i][1]] = val;
			Edge[edge[i][1]][edge[i][0]] = val;
		}

	}
	void print(){
		cout << "Point:";
		for(int i = 0 ; i < Point.size(); i++){
			cout  << Point[i] << " ";
		}
		cout << endl;
		cout << "Edge:" << endl;
		for(int i = 0; i < Edge.size(); i++){
			for(int j = 0; j < Edge[i].size(); j++){
				cout << Edge[i][j] << " ";
			}
			cout << endl;
		}
	}
	void addPoint(int pointNum){
		for(int i = 0; i < Point.size();i++){
			for(int j = 0; j < pointNum;j++){
				Edge[i].push_back(0);
			}
		}
		vector<int> temp(Point.size() + pointNum, 0);
		for(int i = 0; i < pointNum; i++){
			Edge.push_back(temp);
			Point.push_back(1);
		}

	}
	int PointNum(){
		return Point.size();
	}
	void addOneEdge(int start, int end, int val){
		if(start > Point.size() || end > Point.size()){
			cout << "error! the Point must < Point.size()" << endl;
			return;
		}
		Edge[start][end] = val;
	}
	void addOneEdge(int start, int end) {
		if (start > Point.size() || end > Point.size()) {
			cout << "error! the Point must < Point.size()" << endl;
			return;
		}
		Edge[start][end] = 1;
	}
	void addMoreEdge(vector<vector<int>> edge){
		for(int i = 0; i < edge.size(); i++){
			addOneEdge(edge[i][0], edge[i][1]);
		}
	}
	Node* Prime(int root) {
		vector<int> isJoin(Point.size(), 0);
		vector<NodeCoast> lowCost(Point.size());

		for (int i = 0; i < Point.size(); i++) {
			lowCost[i].coast = INT_MAX;
			lowCost[i].pre = -1;
		}
		isJoin[root] == 1;
		lowCost[root].coast = 0;
		Node* Root = new Node(root);
		//
		//
		while()
		//
		int temp = root;
	}
};

int main()
{
	vector<vector<int>> edge{{1,2,2},{2,3},{1,3}};
	Graph graph(4, edge);
	
	graph.print();
	graph.addPoint(2);
	graph.print();
	cout << "the PointNum = " << graph.PointNum() << endl;
	graph.addOneEdge(1,4,2);
	graph.addOneEdge(4,1,2);
	graph.addOneEdge(5,4,3);
	graph.addOneEdge(4,5,3);
	graph.print();
	return 0;
}
