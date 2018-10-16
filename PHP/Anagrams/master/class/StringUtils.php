<?php

namespace Anagram;

use Prophecy\Exception\Exception;

/**
 * Created by edeoleo@gmail.com.
 * User: Elminson De Oleo Baez
 * Date: 6/27/2018
 * Time: 2:46 PM
 */

class StringUtils
{

    /**
     * @param array $words
     * @param string $search
     * @return array
     * @throws \Exception
     */
    public function anagrams(array $words, String $search)
    {

        if (!is_array($words) || $words == "") {
            throw new \TypeError('parameters must be an Array');
        }
        if (!is_string($search) || $search == "" || $search == null) {
            throw new \TypeError('Search parameter must be a String');
        }

        $found_anagram = [];
        foreach ($words as $key => $word) {
            //continue if the string lenght are different
            if (strlen($word) != strlen($search)) {
                continue;
            }
            if ($this->is_anagram($word, $search)) {
                $found_anagram[] = $word;
            }
        }
        return $found_anagram;
    }

    /**
     * MOST EFFICIENT
     * @param $origin
     * @param $tocompare
     * @return bool
     */
    public function is_anagram(string $origin, string $tocompare)
    {
        //count_chars Return information about characters used in a string
        //mode use : 1 (only byte-values with a frequency greater than zero are listed.)
        return (count_chars($origin, 1) == count_chars($tocompare, 1));
    }

    /**
     * This is another way to detect if 2 string are anagrams
     * due the use of str_split and sort(twice) this solution is NOT the most efficient
     * @param $origin
     * @param $tocompare
     * @return bool
     */
    public function is_anagram_another_way($origin, $tocompare)
    {
        $origin = str_split($origin);
        $tocompare = str_split($tocompare);
        sort($origin);
        sort($tocompare);
        return ($origin == $tocompare);
    }
}
