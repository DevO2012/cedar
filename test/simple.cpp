
#include <cstdio>
#include <cstdlib>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef USE_PREFIX_TRIE
#include <cedarpp.h>
#else
#include <cedar.h>
#endif

//typedef cedar::da<int> cedar_t;

template<typename T>
inline void insert_key(cedar::da<T> &t, const char* key, T new_value)
{
  t.update(key) = new_value;
}
template<typename T>
inline bool lookup_key(cedar::da<T> &t, const char* key)
{
  return t.exactMatchSearch<int>(key) >= 0;
}

// --------------------------------------------------------------------------------------------------------------------
int main (int argc, char **argv)
{
  cedar::da<int> trie;

  insert_key(trie,"test",-1);

  if(lookup_key(trie,"test")) {
    printf("lookup_key %i \n",trie.exactMatchSearch<int>("test"));
  }
  if (lookup_key(trie, "none")) {
    printf("lookup_key none %i \n", trie.exactMatchSearch<int>("none"));
  } else {
    printf("lookup_key none %i \n", trie.exactMatchSearch<int>("none"));
  }
  getchar();
  return 0;
}
