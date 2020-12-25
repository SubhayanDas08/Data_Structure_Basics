#include <stdio.h>
#include <stdlib.h>

struct Number
{
    int real;
    int img;
};
struct Number Calculate(struct Number *p1, struct Number *p2)
{
    struct Number res;
    res.real = p1->real + p2->real;
    res.img = p1->img + p2->img;
    return res;
}

void Evaluate(struct Number *p1, struct Number *p2)
{
    struct Number res;
    res.real = p1->real + p2->real;
    res.img = p1->img + p2->img;
    printf("%d %d\n", res.real, res.img);
}
int main()
{
    struct Number *p1, *p2, result;
    p1 = (struct Number *)calloc(1, sizeof(struct Number));
    p2 = (struct Number *)calloc(1, sizeof(struct Number));
    printf("\n p1 is %d %di\n p2 is %d %di\n", p1->real, p1->img, p2->real, p2->img);
    printf("Enter the first Number (real then Img part) : ");
    scanf("%d%d", &p1->real, &p1->img);
    printf("Enter the Second Number (real then Img part) : ");
    scanf("%d%d", &p2->real, &p2->img);
    printf("\n p1 is %d %di\n p2 is %d %di\n", p1->real, p1->img, p2->real, p2->img);
    Evaluate(p1, p2);
    result = Calculate(p1, p2);
    printf("\nDisplay the Resultant number : \n");
    printf("%d + %di", result.real, result.img);
}