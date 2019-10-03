#include<bits/stdc++.h>
#define lli long long
using namespace std;

struct Point
{
    int x, y;
};
vector<Point> p;
vector<Point> q;
int orien(Point p, Point q, Point r){
    lli val=((lli)(q.x-p.x)*(lli)(r.y-q.y))-((lli)(q.y-p.y)*(lli)(r.x-q.x));
    if(val==0) return 0; //colinear
    if(val>0) return -1; //ACW
    return 1; //CW
}


lli dist(Point p1, Point p2){
        return ((lli)(p1.x-p2.x)*(lli)(p1.x-p2.x)+(lli)(p1.y-p2.y)*(lli)(p1.y-p2.y));
}


bool comp(Point p1, Point p2){
    int temp = orien(p1,p[0],p2);
    if(temp==0) return (dist(p1,p[0])<dist(p2,p[0]));
    else if(temp==-1) return false;
    return true;
}

Point ntt(){

}

int main(){

    int t;
    cin>>t;
    int x,y;
    Point pt;

    for(int i=0;i<t;i++){
        cin>>x>>y;
        pt.x = x;
        pt.y = y;
        p.push_back(pt);

    }
    int ymin = p[0].y, xmin=p[0].x,mi=0;
    for(int i=1;i<t;i++)
        {
            if((p[i].y<ymin)||(p[i].y==ymin&&p[i].x<xmin)){
                ymin = p[i].y;
                xmin = p[i].x;
                mi = i;
            }

        }

swap(p[0],p[mi]);

sort(p.begin()+1,p.end(),comp);

/*for(int i=0;i<t;i++)
{
    cout<<p[i].x<<" "<<p[i].y<<endl;
}*/

q.push_back(p[0]);
for(int i=1;i<t-1;i++){
    int temp = orien(p[0],p[i],p[i+1]);
    if(temp!=0) q.push_back(p[i]);
    }
    if(orien(p[0],p[t-2],p[t-1])!=0) q.push_back(p[t-1]);

    if(q.size()<3) {
        cout<<-1;
        exit(0);
    }
/*
cout<<"%"<<endl;
for(int i=0;i<q.size();i++){
    cout<<q[i].x<<" "<<q[i].y<<endl;
}
cout<<"%"<<endl;*/
stack<Point> s;

s.push(q[0]);
s.push(q[1]);
s.push(q[2]);

for(int i=3;i<q.size();i++){

    Point temp = s.top();
    s.pop();
    Point ntt = s.top();
    s.push(temp);
    while(orien(ntt,s.top(),q[i])!=-1){
        s.pop();
        temp = ntt;
        s.pop();
        ntt = s.top();
        s.push(temp);
    }

    s.push(q[i]);

}

vector<Point> ans;

while(!s.empty()){
    //cout<<s.top().x<<" "<<s.top().y<<endl;
    ans.push_back(s.top());
    s.pop();
}
int len = ans.size();
xmin = p[0].x;
mi = 0;
ymin = p[0].y;
for(int i=1;i<len;i++){
    if(xmin>p[i].x||(xmin==p[i].x&&(ymin>p[i].y))){
        xmin = p[i].x;
        ymin = p[i].y;
        mi=i;
    }
}

cout<<len<<endl;
for(int i=0;i<len;i++)
{
    cout<<ans[(mi+i)%len].x<<" "<<ans[(mi+i)%len].y<<endl;
}




return 0;}
