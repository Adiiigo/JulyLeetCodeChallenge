There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .

Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .

Note:

    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.

   Hide Hint #1  
This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
   Hide Hint #2  
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
   Hide Hint #3  
Topological sort could also be done via BFS.

Solution:

//Approach 1:
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>&p) {
               
        vector<vector<int>>dependee(numCourses) ;
        vector<int>indegree(numCourses , 0) ;
        vector<int> answer ;

        int length = p.size() ;
        for(int i = 0 ; i < length ; i++){
            dependee[ p[i][1] ].push_back( p[i][0] ) ;
            indegree[ p[i][0] ]++;
        }
        
        //print dependee table
        for(int i = 0 ; i < numCourses ; i++){
            cout << i << "->" ;
            // cout << dependee[i][0] << "->" ;
            for(int j = 0 ; j < dependee[i].size() ; j++ ){
                cout << dependee[i][j] ;
            }
            cout << endl ;
        }
        
        //print indegree
        for(int i = 0 ; i < numCourses ; i++){
            cout << i << "|" << indegree[i] << endl;
        }
        
        auto it = find(indegree.begin() , indegree.end() , 0) ;
        
        while(it != indegree.end()){
            
            //find pos 
            int pos = it-indegree.begin() ;
            answer.push_back(pos) ;
            indegree[pos] = -1 ;
            for(int i = 0 ; i < dependee[pos].size() ; i++){
                indegree[dependee[pos][i]]-- ;
            }
            it = find(indegree.begin() , indegree.end() , 0) ;
        }
        
        if(answer.size() != numCourses){
            vector<int>temp ;
            return temp ;
        }
               
        return answer;
    }
};

Time Complexity - O(numCourses)
Space Complexity - O(edges)

TestCases
4
[[1,0],[2,0],[3,1],[3,2]]
5
[[1,0],[3,0],[2,1],[3,1],[2,3],[4,3]]
5
[[1,0],[2,1],[0,2],[1,3],[1,4]]
