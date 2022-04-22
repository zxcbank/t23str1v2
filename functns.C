void CountAllLetters( char *str, int *letter ) // подсчет каждой буквы, в мейне вводим массив на 26
{
  int i, len;

  for (i = 0; i < 26; i++)
    letter[i] = 0;

  len = strlen(str);
  for (i = 0; i < len; i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
      letter[str[i] - 'a']++;
    if (str[i] >= 'A' && str[i] <= 'Z')
      letter[str[i] - 'A']++;
  }
}

int IsPalindrom( char *str ) // 6
{
  int b = 0, e = strlen(str) - 1;

  while (b < e)
  {
    while(isspace((unsigned char)str[b]))
      b++;
    while(isspace((unsigned char)str[e]))
      e--;
    if (str[b++] != str[e--])
      return 0;
  }
  return 1;
}

void WordCount( char *str, int *words, int *symwords ) // 8 + 9, добавить симвордс = 0 в мейне
{
  int i = 0, begin, end;

  while (str[i] != 0)
  {
    /* find begin and end of each word and handle them as needed */
    while(isspace((unsigned char)str[i]))
      i++;
    if (str[i] != 0)
    {
      begin = i;
      while (str[i] != 0 && !isspace((unsigned char)str[i]))
        i++;
      end = i - 1;
    }
    (*words)++;
    *symwords += Issymm(begin, end);
  }
}

int SumWInt (char *str)
{
  int i = 0, cnt = 0, num = 0, a = 0, summ = 0, wb, we;
  while (str[i] != 0)
  {
    while (isspace((unsigned char) str[i]))
      i++;
    if (str[i] != 0)
    {
      wb = i;
      a = 0;
      while (str[i] != 0 && !isspace((unsigned char) str[i]))
      {
        if (str[i] >= '0' && str[i] <= '9')
	    {
	      num = str[i] - '0';
	      a = a * 10 + num;
	    }
        i++;
      }
      we = i - 1;
      summ += a;
    }
  }
  return summ;
}

double SumWReal (char *str)
{
  int i = 0;
  double summ = 0, tochka = 0, pow = 10,  b = 0,  a = 0;
  while (str[i] != 0)
  {
    while (isspace((unsigned char) str[i]))
      i++;
    if (str[i] != 0)
	  {
      a = 0;
      b = 0;
      pow = 10;
      while (str[i] != 0 && !isspace((unsigned char) str[i]))
      {
        if (str[i] == '.')
          tochka = 1;
        if (str[i] >= '0' && str[i] <= '9')
        {
          if (tochka)
          {
            a += ((double) (str[i] - '0') / pow);
            pow *= 10;
          }
          else
            a = a * 10 + str[i] - '0';
        }
      i++;
    }
	  tochka = 0;
	  summ += a;
	}
  }
  return summ;
}
