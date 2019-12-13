int mx_factorial_iter(int n) {
    int factorial;
    
    if (n < 0 || n > 12) return 0;
    for(factorial = 1; n > 1; factorial *= (n--));
    return factorial;
}
