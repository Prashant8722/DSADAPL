#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *randstr ( int l )
{
   char *S;
   int i;

   S = (char *)malloc((l+1) * sizeof(char));
   S[l] = '\0';
   for (i=0; i<l; ++i) S[i] = '0' + (char)(rand() & 1);
   return S;
}

/* This is the modified KMP function that finds all matches of T in S
   by computing the failure function of TS. We have |S| = n and |T| = m. */
int *KMP ( char *S, char *T, int n, int m )
{
   char *TS;
   int i, j, *match, *F, *G, cnt;

   /* First concatenate T and S to TS */
   TS = (char *)malloc((n+m)*sizeof(char));
   for (i=0; i<m; ++i) TS[i] = T[i];
   for (i=0; i<n; ++i) TS[m+i] = S[i];

   /* Then compute the failure function for TS in the usual way */
   F = (int *)malloc((n+m)*sizeof(int));
   F[0] = 0; i = 1; j = 0;
   while (i < m+n) {
      while ((i < m+n) && (TS[i] == TS[j])) F[i++] = ++j;
      if (j == 0) F[i++] = 0; else j = F[j-1];
   }

   /* G[] is an array of size m+n with G[i] intended for storing the
      information whether T is a border (not necessarily proper) of
      TS[0...i] */
   G = (int *)malloc((m+n)*sizeof(int));
   for (i=0; i<=m-2; ++i) G[i] = 0;  /* T cannot be a border in a string of length < m */
   G[m-1] = 1;                       /* T is definitely a border of T */
   cnt = 0;                          /* cnt stores the number of matches found so far */
   for (i=m; i<m+n; ++i) {           /* T is a proper border for larger strings */
      if (F[i] < m) G[i] = 0;        /* The longest proper border is shorter than T */
      else if (F[i] == m) G[i] = 1;  /* T is the longest proper border */
      else G[i] = G[F[i]-1];         /* Check whether T is a border of the longest proper border */

      if ((i >= 2*m - 1) && (G[i])) ++cnt; /* Match found */
   }

   /* Copy the match locations in the array match[]. At this moment, cnt
      stores the exact number of matches. So a precise size allocation for
      match[] is posssible. */
   match = (int *)malloc((cnt+1)*sizeof(int));
   match[0] = cnt; /* Store the number of matches in match[0].
                      match[1], match[2], ..., match[cnt] will store the matching indices. */
   j = 1;          /* j is now used as the writing location in match[] */
   for (i=2*m-1; i<m+n; ++i) if (G[i]) match[j++] = i - 2*m + 1;

   /* Clean up locally allocated memory */
   free(TS); free(F); free(G);

   /* Return the list of matching indices followed by the count of matches */
   return match;
}

/* This is the function that does string matching based upon the modified KMP
   algorithm implemented abobe. */
void strmatch ( int n, int m )
{
   char *S, *T;
   int *match, i;

   S = randstr(n); T = randstr(m);
   printf("S = %s\n", S);
   printf("T = %s\n", T);
   match = KMP(S,T,n,m);
   printf("%d matches found at indices", match[0]);
   for (i=1; i<=match[0]; ++i) printf(" %d", match[i]);
   printf("\n");
   free(S); free(T); free(match);
}

/* This is the function that does string matching based upon the modified KMP
   algorithm implemented abobe. */
void patmatch ( int n , int m )
{
   char *S, *T1, *T2;
   int m1, m2, *match1, *match2;
   int i, j, k;

   /* Generate S, T1 and T2 randomly */
   S = randstr(n);
   m1 = m - 1; T1 = randstr(m1);
   m2 = m; T2 = randstr(m2);
   printf("S = %s\n", S);
   printf("T = %s*%s\n", T1, T2);

   /* Find all matches of T1 and T2 in S */
   match1 = KMP(S,T1,n,m1);
   match2 = KMP(S,T2,n,m2);

   printf("Pattern matches at index pairs");
   for (i=j=1; i<=match1[0]; ++i) { /* For each match of T1 in S */
      k = match1[i] + m1;           /* Match for T2 in S cannot start before index k */

      if (k > match2[match2[0]]) break; /* No further match possible */

      /* Find the first location of a match */
      while ((j <= match2[0]) && (k > match2[j])) ++j;

      /* Each following match of T2 in S produces a pattern match */
      for (k=j; k<=match2[0]; ++k) printf(" (%d,%d)", match1[i], match2[k]);
   }
   printf("\n");

   /* Clean up locally allocated memory */
   free(S); free(T1); free(T2); free(match1); free(match2);
}

int main ( int argc, char *argv[] )
{
   int n, m;

   srand((unsigned int)time(NULL));
   if (argc >= 3) {
      n = atoi(argv[1]); m = atoi(argv[2]);
   } else {
      printf("n = |S| = "); scanf("%d", &n);
      printf("m = |T| = "); scanf("%d", &m);
   }
   printf("\n*** String matching\n"); strmatch(n,m);
   printf("\n*** Pattern matching\n"); patmatch(n,m);
   exit(0);
}