#include <functional>
#include <iostream>
#include <thread>
#include <vector>

std::vector<std::pair<int, int>> balance_load(const int range_min, const int range_max, unsigned int num_workers);

std::vector<int> parallell_transform(const std::vector<int> &vec_a, const std::vector<int> &vec_b, std::function<int(int, int)> func)
{
  // Her legges resultatet av operasjonen.
  std::vector<int> result(vec_a.size());

  std::vector<std::pair<int, int>> subloads = balance_load(0, vec_a.size(), std::thread::hardware_concurrency());

  std::vector<std::thread> threads;

  for (std::pair<int, int> subload : subloads)
  {
    // Start en ny tråd som bruker
    threads.emplace_back([subload, &vec_a, &vec_b, &func, &result]()
                         {
      // Kjør 'func' på alle indekser definert av underlasten 'subload'.
      for (int i = subload.first; i < subload.second; ++i) {
        result[i] = func(vec_a[i], vec_b[i]);
      } });
  }

  // Vent på at alle trådene har kjørt ferdig.
  for (std::thread &t : threads)
    t.join();

  return result;
}

/// @brief Regner ut en jevn fordeling av det totale arbeidet (definert
///        av 'range_min' og 'range_max') fordelt over 'num_workers'
///        antall threads. Denne operasjonen er indeks-basert, og antar at
///        hver indeks krever like mye arbeid. Eventuell rest-last som
///        ikke kan fordeles jevnt utover alle trådene, fordeles utover
///        de første trådene.
/// @param range_min Første inklusive indeks i intervallet.
/// @param range_max Siste eksklusive indeks i intervallet.
/// @param num_workers Antall tråder man ønsker å fordele arbeidet utover.
/// @return En vector av std::pair. pair::first inneholder første indeks (inklusiv), og pair::second inneholder siste indeks (eksklusiv).
std::vector<std::pair<int, int>> balance_load(const int range_min, const int range_max, unsigned int num_workers)
{
  // Dette er den totale lasten.
  const int load = range_max - range_min;

  // Dette er rest-lasten som ikke kan spres likt utover alle threads.
  const int remainder = load % num_workers;

  // Dette er lasten per thread, ekskludert eventuell rest-last.
  const int subload_size = (load - remainder) / num_workers;

  // Hvis 'subload_size' er 0, trenger vi bare 'remainder' antall threads.
  const int subload_count = subload_size > 0 ? num_workers : remainder;

  // Her legges alle last-grensene. pair::first inneholder første indeks (inklusiv), og pair::second inneholder siste indeks (eksklusiv)
  std::vector<std::pair<int, int>> subloads(subload_count);

  // Inneholder alltid siste indeks fra forrige iterasjon i kommende løkke.
  int previous_end = range_min;

  for (int i = 0; i < subloads.size(); ++i)
  {
    // Hver last inneholder underlasten, pluss eventuell rest-last.
    int current_load = subload_size + (i < remainder);
    int start = previous_end;
    int end = start + current_load;

    subloads[i].first = start;
    subloads[i].second = end;

    previous_end = end;
  }

  return subloads;
}

int main()
{
  using namespace std;

  // ### The untouchable zone ###
  vector<int> a = {1, 2, 3, 4, 5};
  vector<int> b = {2, 3, 4, 5, 6};

  auto result = parallell_transform(a, b, [](int a_element, int b_element)
                                    { return a_element + b_element; });
  for (auto &e : result)
    cout << e << ' ';
  cout << endl;

  result = parallell_transform(a, b, [](int a_element, int b_element)
                               { return a_element * b_element; });
  for (auto &e : result)
    cout << e << ' ';
  cout << endl;
  // ### The untouchable zone ###

  return 0;
}