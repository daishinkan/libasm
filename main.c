/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekindomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:24:13 by ekindomb          #+#    #+#             */
/*   Updated: 2020/03/06 17:23:06 by ekindomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/*
 ** Macros
 */

#define STRLEN(x)		printf("`%s` = %d (%d)\n", x, ft_strlen(x), (int)strlen(x));
#define STRCPY(x,y)		printf("`ft_strcpy` = |%s| strcpy = |%s|\n ", ft_strcpy(x,y), strcpy(x,y));
#define STRCMP(x,y)		printf("`ft_strcmp` = |%d| strcmp = |%d|\n", ft_strcmp(x,y), strcmp(x,y));
#define WRITE(x,y,z)	printf("`ft_write` = |%ld| write = |%ld|\n", ft_write(x,y,z), write(x,y,z));
#define READ(x,y,z)		rdm = ft_read(x, y, z); printf("buffer read : %s, value return %ld\n", buffer, rdm);
#define STRDUP(x)       printf("`ft_strdup` = |%s| strdup = |%s|\n", ft_strdup(x), strdup(x));
/*
 ** Functions prototypes
 */

int		ft_strlen(const char *s);
char	*ft_strcpy(char *dest, char *s);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, char *str, size_t len);
ssize_t	ft_read(int fd, char *str, size_t len);
char *ft_strdup(char *str);
/*
 ** Entrypoint
 */

int 			main(int ac, char **av)
{
    int			i;
    ssize_t 		rdm;
    (void) ac;
    (void) av;
    char *str = "je suis content";
    char *dst;
    char buffer[255];
    int fd;
    char *str1 = "copy success";

    i = 0;
    rdm = 0;
    while (i < 255)
        buffer[i++] = '\0';

    if (!(dst = (char *)malloc(sizeof(char) * 100)))
        return (0);

    printf("====FT_STRLEN====\n");
    STRLEN("Nothing turn in");
    STRLEN("Bonjour comment vas tu?");
    STRLEN("");
    STRLEN("bon");
    STRLEN("bonjour");
    STRLEN("%c%s%p%x%X%e%f%g");
    STRLEN("the\0hidden");
    STRLEN("Lorem ipsum dolor sit amet, consectetur adipiscing\
            elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
            bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
            volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
            felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
            ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
            tortor, sit amet consequat amet.");
    printf("=====FT_STRCPY====\n");
    STRCPY(dst, "Bonjour comment vas tu?");
    STRCPY(dst, "");
    STRCPY(dst, "toto");
    STRCPY(dst, "");
    STRCPY(dst, "abc");
    STRCPY(dst, "asl;fjl;asdjfjkasdl;fjadjsf");
    STRCPY(dst,"yope\0la");
    STRCPY(dst,"Lorem ipsum dolor sit amet, consectetur adipiscing\
            elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
            bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
            volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
            felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
            ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
            tortor, sit amet consequat amet.");
    STRCPY(dst,"\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f");
    STRCPY(dst,"\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f");
    printf("=====FT_STRCMP=====\n");
    STRCMP("bonjour", "bonjour");
    STRCMP("", "");
    STRCMP("bon", "");
    STRCMP("bonjour", "");
    STRCMP("%c%s%p%x%X%e%f%g", "");
    STRCMP("toto", "");
    STRCMP("", "asdf");
    STRCMP("bon", "bo");
    STRCMP("bonjour", "onjour");
    STRCMP("%c%s%p%x%X%e%f%g", "%s%p%x%X%e%f%g");
    STRCMP("the\0hidden", "thehidden");
    STRCMP("Lorem ipsum dolor st amet, consectetur adipiscing", "Lodsfsdfasdf");
    STRCMP("\x01", "\x01");
    STRCMP("\x02", "\x01");
    STRCMP("\x01", "\x02");
    STRCMP("\xff", "\xff");
    STRCMP("\xfe", "\xff");
    STRCMP("\xff", "\xfe");
    STRCMP("\x01\x01", "\x01");
    STRCMP("\x01\x02", "\x01");
    STRCMP("\x02\x01", "\x02");
    STRCMP("\xff\xff", "\xff");
    STRCMP("\xff\xfe", "\xff");
    STRCMP("\xfe\xff", "\xfe");
    STRCMP("\x01", "\x01\x01");
    STRCMP("\x01", "\x01\x02");
    STRCMP("\x02", "\x02\x01");
    STRCMP("\xff", "\xff\xff");
    STRCMP("\xff", "\xff\xfe");
    STRCMP("\xfe", "\xfe\xff");
    printf("====FT_WRITE======\n");
    WRITE(STDOUT_FILENO, "BONJOUR COMMENT VAS TU", 22);
    WRITE(STDOUT_FILENO, str, ft_strlen(str));
    WRITE(STDOUT_FILENO,"",ft_strlen(""));
    WRITE(STDOUT_FILENO, "bon", ft_strlen("bon"));
    WRITE(STDOUT_FILENO,"bonjour", ft_strlen("bonjour"));
    WRITE(STDOUT_FILENO,"%c%s%p%x%X%e%f%g",ft_strlen("%c%s%p%x%X%e%f%g"));
    WRITE(STDOUT_FILENO,"the\0hidden", ft_strlen("the\0hidden"));
    WRITE(STDOUT_FILENO,"Lorem ipsum dolor sit amet, consectetur adipiscing\
            elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
            bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
            volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
            felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
            ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
            tortor, sit amet consequat amet.", ft_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing\
            elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
            bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
            volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
            felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
            ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
            tortor, sit amet consequat amet."));

    WRITE(STDOUT_FILENO, NULL, 3);
    WRITE(-1, "bonjour", 7);
    WRITE(42, "bonjour", 7);
    WRITE(9809, "bonjour", 7);
    WRITE(98123, "", 1);
    WRITE(42, NULL, 7);
    printf("====FT_READ======\n");
    const char *array[100] = 
    {
        "tests/files_ft_read/t1",
        "tests/files_ft_read/t2",
        "tests/files_ft_read/t3",
        "tests/files_ft_read/tt",
        NULL
    };
    i = 0;
    int count;
    count = 0;
    while (array[i])
    {
        count++;
        i++;
    }

    i = 0;
    while (i < count)
    {
        fd = open(array[i], O_RDONLY);
        READ(fd, buffer, 255);
        close(fd);
        i++;
    }
    READ(STDOUT_FILENO, NULL, 3);
    READ(-1, "bonjour", 7);
    READ(42, "bonjour", 7);
    READ(9809, "bonjour", 7);
    READ(98123, "", 1);
    READ(42, NULL, 7);
    printf("====FT_STRDUP====\n");
    STRDUP(str1);
    STRDUP("all is good!");

    STRDUP("");
    STRDUP("abc");
    STRDUP("asl;fjl;asdjfjkasdl;fjadjsf");
    STRDUP("yope\0la");
    STRDUP("Lorem ipsum dolor sit amet, consectetur adipiscing\
            elit. Sed in malesuada purus. Etiam a scelerisque massa. Ut non euismod elit. Aliquam\
            bibendum dolor mi, id fringilla tellus pulvinar eu. Fusce vel fermentum sem. Cras\
            volutpat, eros eget rhoncus rhoncus, diam augue egestas dolor, vitae rutrum nisi\
            felis sed purus. Mauris magna ex, mollis non suscipit eu, lacinia ac turpis. Phasellus\
            ac tortor et lectus fermentum lobortis eu at mauris. Vestibulum sit amet posuere\
            tortor, sit amet consequat amet.");
    STRDUP("\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f");
    STRDUP("\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0b\x0c\x0d\x0e\x0f");
    return (0);
}	
