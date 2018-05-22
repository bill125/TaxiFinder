#include <iostream>
#include <cstdio>
// #include <pair>
#include <vector>

using namespace std;

int main()
{
    // freopen("../data/road.nedge", "r", stdin);
    // freopen("road.nedge", "w", stdout);
    
    // int n, m;
    // scanf("%d%d", &n, &m);

    // for (int i = 0; i < m; ++ i) {
    //     int a, b, c;
    //     scanf("%d %d %d", &a, &b, &c);
    //     if (c <= 10)
    //         printf("%d %d %d\n", a, b, c);
    // }

    // fclose(stdin);
    // fclose(stdout);

    freopen("../data/road.cnode", "r", stdin);
    freopen("../data/road_js.cnode", "w", stdout);

    int n = 0;
    double avg_x = 0., avg_y = 0.;
    int id;
    double x, y;
    vector<pair<double, double> > points;
    while (scanf("%d %lf %lf", &id, &x, &y) != EOF) {
        points.push_back(make_pair(x, y));
        avg_x += x;
        avg_y += y;
        ++ n;
    }
    avg_x /= 1. * n;
    avg_y /= 1. * n;
    printf("%d\n", n);
    for (int i = 0; i < n; ++ i) {
        printf("%.5f %.5f\n", points[i].first, points[i].second);
    }
    // printf("%.5f %.5f\n", avg_x, avg_y);

    fclose(stdin);
    fclose(stdout);

    return 0;
}