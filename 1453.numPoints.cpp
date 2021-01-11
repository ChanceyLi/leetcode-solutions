//算法没得问题，但是超出时间限制。
class Solution {
public:
    double dist(vector<double> p1, vector<double> p2) {//距离
        return sqrt((p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]));
    }
    vector<double> f(vector<double> a, vector<double> b, int r) {//圆心
        vector<double> mid{(a[0]+b[0])/2.0,(a[1]+b[1])/2.0};
        double d = dist(a,mid);
        double h = sqrt(r*r - d*d);
        double ba0 = b[0] - a[0], ba1 = b[1] - a[1];
        double hd0 = -ba1, hd1 = ba0;
        double len = sqrt(hd0*hd0+hd1*hd1);
        hd0 /= len;hd1 /= len;
        hd0 *= h;hd1 *= h;
        return vector<double>{hd0 + mid[0], hd1 + mid[1]};
    }
    int numPoints(vector<vector<int>>& points, int r) {
        int n = points.size();
        int res = 1;
        vector<vector<double>> p(n, vector<double>(2,0));//将原来的points改成vector<double>组
        for(int i = 0; i < n; ++i) {
            p[i][0] = (double)points[i][0];
            p[i][1] = (double)points[i][1];
        }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) {
                if(dist(p[i],p[j]) > 0 && dist(p[i],p[j]) <= 2 * r) {//两点不重合且距离小于2r时求解圆心并遍历所有点
                    vector<double> tmp = f(p[i], p[j], r);
                    int tmp_res = 0;
                    for(int k = 0; k < n; ++k) {
                        double dist_k = dist(tmp, p[k]);
                        if(dist_k <= r) ++tmp_res;
                    }
                    res = max(tmp_res, res);
                }
            }
        return res;
    }
};
