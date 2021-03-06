//
// Created by Tanner on 5/24/2017.
//

#ifndef DAILY_PROG_316I_PROMOTION_H
#define DAILY_PROG_316I_PROMOTION_H

#include <string>
#include <map>
#include <utility>
#include <vector>

/**
 * This class provides a set of rules by which promotions may be applied to a Cart. The m_rules member contains key-value
 * pairs where the key is the ID of a Tour object that the Promotion applies to, and the value is the minimum number of these tours
 * that must be present in a Cart for the promotion to apply. The Promotion will only be applied to the Cart if every
 * key and its corresponding value are present in the Cart.
 */
class Promotion {
public:

    /**
     *
     * @param promo_id is the unique ID associated with this Promotion
     */
    Promotion(std::string const &promo_id);

    /**
     *
     * @param tour_id corresponds to the ID of a Tour for which the Promotion applies to
     * @param amt_req is the amount of tours of the given tour_id that must be present for the promo to apply
     * @param discount is the discount to be applied
     * @param discountIsPerItem should be sent as true if the discount is to be multiplied by the number of tours with the proper id that are present
     * @return true if the rule was successfully added, false otherwise
     */
    bool addRule(std::string const &tour_id, unsigned int const &amt_req, unsigned int const &discount,
                 bool const discountIsPerItem = false);

    /**
     *
     * @param tour_id corresponds to the ID of a Tour for which the Promotion applies to
     * @param amt_req is the amount of tours of the given tour_id that must be present for the promo to apply
     * @param freebies contains freebie pairs where the first item in the pair is the ID of the tour for which freebies will be given, and the second item is the amount of freebies to be given
     * @return true if the rule was successfully added, false otherwise
     */
    bool addRule(std::string const &tour_id, unsigned int const &amt_req,
                 std::vector<std::pair<std::string, unsigned int>> const &freebies);

    std::map<std::string, unsigned int> getRules() const { return m_rules; }

    std::string getID() const { return m_promo_id; }

    unsigned int getDiscount() const { return m_discount; }

    unsigned int getDiscountPerItem() const { return m_discount_per_item; }

    std::vector<std::pair<std::string, unsigned int>> getFreebies() const { return m_freebies; };

    /**
     * Completely overwrites the current discount and makes it the value provided instead
     *
     * @param newDiscount the new discount value for the Promotion
     */
    void updateDiscount(unsigned int const &newDiscount);

    /**
     * Takes the current discount value, and adds modAmt to it
     *
     * @param modAmt is the number to be added to the current discount value
     */
    void modifyDiscount(int const &modAmt);

    /**
     * Completely overwrites the current discount and makes it the value provided instead
     *
     * @param newDiscount the new discount value for the Promotion
     */
    void updateDiscountPerItem(unsigned int const &newDiscount);

    /**
     * Takes the current discount value, and adds modAmt to it
     *
     * @param modAmt is the number to be added to the current discount value
     */
    void modifyDiscountPerItem(int const &modAmt);

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

    /**
     * A Vector object containing pairs, which contain the IDs of the Tours to be given for free as the key, and
     * the number of those Tours to be given for free as the value. m_freebies is defaultly constructed if not applicable.
     */
    std::vector<std::pair<std::string, unsigned int>> m_freebies;

    /**
     * An unsigned int containing the value of the total discount to be applied.
     * m_discount is initialized to 0 if not applicable.
     */
    unsigned int m_discount;

    /**
     * An unsigned int containing the value of the total discount to be applied.
     * m_discount_per_item is initialized to 0 if not applicable.
     */
    unsigned int m_discount_per_item;

};


#endif //DAILY_PROG_316I_PROMOTION_H
