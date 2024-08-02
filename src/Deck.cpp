//
// Created by Matthew on 4/08/2024.
//

#include <cassert>
#include <random>
#include <stdexcept>
#include "../include/Deck.h"

namespace ka {

Deck::Deck() {
  auto card_index = 0;
  for (auto suit: all_suits) {
	for (auto i { Rank::min_value }; i <= Rank::max_value; ++i) {
	  m_cards.emplace_back(Rank { i }, suit);
	  ++card_index;
	}
  }
  assert(m_cards.size() == Card::count);
}

auto Deck::deal() -> Card {
  if (m_cards.empty()) {
	throw std::runtime_error("Deck is empty");
  }
  auto const card { m_cards.back() };
  m_cards.pop_back();
  return card;
}

auto Deck::empty() const -> bool {
  return m_cards.empty();
}

auto Deck::shuffle(std::random_device& rd) -> void {
  std::shuffle(m_cards.begin(), m_cards.end(), rd);
}

} // ka