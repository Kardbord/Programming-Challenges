//
// Created by Tanner on 5/24/2017.
//

#ifndef DAILY_PROG_316I_PROMOTION_H
#define DAILY_PROG_316I_PROMOTION_H

#include <string>
#include <map>
#include <utility>

// TODO: update this class such that the nature of the promotion is described (you know, the whole point of all of this)

/**
 * This class provides a set of rules by which promotions may be applied to a Cart. The m_rules member contains key-value
 * pairs where the key is the ID of a Tour object that the Promotion applies to, and the value is the minimum number of these tours
 * that must be present in a Cart for the promotion to apply. The Promotion will only be applied to the Cart if every
 * key and its corresponding value are present in the Cart.
 */
class Promotion {
public:

    /**
     * @param promo_id is the unique ID associated with this Promotion
     * @param tour_id corresponds to the ID of a Tour for which the Promotion applies to.
     * @param amt_req is the amount of tours of the given tour_id that must be present for the promo to apply
     */
    Promotion(std::string const &promo_id, std::string const &tour_id, unsigned int const &amt_req);

    /**
     *
     * @param tour_id corresponds to the ID of a Tour for which the Promotion applies to
     * @param amt_req is the amount of tours of the given tour_id that must be present for the promo to apply
     * @return true if the rule was successfully added, false otherwise
     */
    bool addRule(std::string const &tour_id, unsigned int const &amt_req);

    std::map<std::string, unsigned int> getRules() const { return m_rules; }

    std::string getID() const { return m_promo_id; }

private:

    /**
     * A Map object where the key is a string corresponding to the ID of a Tour for which the Promotion applies to.
     * The value is the minimum number of tours with the given ID that must be present for the discount to apply.
     */
    std::map<std::string, unsigned int> m_rules;

    /**
     * The unique ID of this Promotion
     */
    std::string m_promo_id;

    // TODO: add bool m_givesFreebie and implement appropriately

    // TODO: add bool m_givesDiscount and implement appropriately

    // TODO: somehow track freebies and/or discounts to be applied

};


#endif //DAILY_PROG_316I_PROMOTION_H
