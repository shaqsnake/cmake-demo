const double eps = 1e-6;

double sqrt(double x) {
    double l = 0, r = x;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if ( mid * mid >= x) r = mid;
        else l = mid; 
    }

    return l;
}