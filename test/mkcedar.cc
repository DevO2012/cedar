// cedar -- C++ implementation of Efficiently-updatable Double ARray trie
//  $Id: mkcedar.cc 1853 2014-06-20 15:04:03Z ynaga $
// Copyright (c) 2013-2014 Naoki Yoshinaga <ynaga@tkl.iis.u-tokyo.ac.jp>
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

int main (int argc, char **argv) {
  if (argc < 3)
    { std::fprintf (stderr, "Usage: %s keys trie\n", argv[0]); std::exit (1); }
  //
  cedar::da <int> trie;
  int n = 0;
  FILE* fp = argv[1][0] == '-' ? stdin : std::fopen (argv[1], "r");
  char line[8192];
  while (std::fgets (line, 8192, fp))
    trie.update (line, std::strlen (line) - 1, n++);
  std::fclose (fp);
  //
  if (trie.save (argv[2]) != 0)
    { std::fprintf (stderr, "cannot save trie: %s\n", argv[2]); std::exit (1); }
  //
  std::fprintf (stderr, "keys: %ld\n", trie.num_keys ());
  std::fprintf (stderr, "size: %ld\n", trie.size ());
  std::fprintf (stderr, "nonzero_size: %ld\n", trie.nonzero_size ());
  return 0;
}
