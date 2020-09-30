#include <stdio.h>

int main()
{
    printf("%d\n", ft_atoi("---+--+1234ab567"));
    printf("%d\n", ft_atoi("does not work: 512"));
    printf("%d\n", ft_atoi("512"));
    printf("%d\n", ft_atoi("512.035"));
    printf("%d\n", ft_atoi("   512.034"));
    printf("%d\n", ft_atoi("512+34"));
    printf("%d\n", ft_atoi("\t\n\t\r\v   512 ottles onr the wall"));
    printf("%d\n", ft_atoi("does not work: 512"));
    return (0);
}
