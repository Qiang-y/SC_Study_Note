#include<iostream>
#include<vector>
using namespace std;

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
			Edge[edge[i][0] - 1][edge[i][1] - 1] = 1;
			Edge[edge[i][1] - 1][edge[i][0] - 1] = 1;
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
	void addOneEdge(int start, int end){
		if(start > Point.size() || end > Point.size()){
			cout << "error! the Point must < Point.size()" << endl;
			return;
		}
		Edge[start-1][end-1] = 1;
	}
	void addMoreEdge(vector<vector<int>> edge){
		for(int i = 0; i < edge.size(); i++){
			addOneEdge(edge[i][0], edge[i][1]);
		}
	}

};

int main()
{
	vector<vector<int>> edge{{1,2},{2,3},{1,3}};
	Graph graph(3, edge);
	
	graph.print();
	graph.addPoint(2);
	graph.print();
	cout << "the PointNum = " << graph.PointNum() << endl;
	graph.addOneEdge(1,4);
	graph.print();
	return 0;
}
