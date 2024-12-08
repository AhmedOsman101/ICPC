<?php

declare(strict_types=1);

function sum_strings($a, $b): string {
  [$a, $b] = [strrev($a), strrev($b)];
  $res = "";
  $len = max(strlen($a), strlen($b)) + 1;
  $carry = 0;
  for ($i = 0; $i < $len; $i++) {
    // echo "S///////////////////////////////////////////////////////////////////\n";
    $na = isset($a[$i]) ? (int) $a[$i] : 0;
    $nb = isset($b[$i]) ? (int) $b[$i] : 0;
    // echo "values:" . $na + $nb . " remainder:" . $carry . PHP_EOL;
    if (($na + $nb + $carry) < 10 and !empty($carry)) {
      $res .= $na + $nb + $carry;
      $carry = 0;
    } elseif (($na + $nb + $carry) >= 10 and !empty($carry)) {
      $res .= $na + $nb + $carry - 10;
      $carry = 1;
    } elseif (($na + $nb) < 10 and empty($carry)) {
      $res .= $na + $nb + $carry;
      $carry = 0;
    } elseif (($na + $nb) >= 10 and empty($carry)) {
      $res .= ($na + $nb) - 10;
      $carry = 1;
    }
    // echo "E///////////////////////////////////////////////////////////////////\n\n";
  }
  return ltrim(strrev($res), "0");
}

$n = trim(fgets(STDIN));
$m = trim(fgets(STDIN));

$final = "";
$carry = 0;

for ($i = 0; $i < strlen($m); $i++) {
  $res = "";
  for ($j = 0; $j < strlen($n); $j++) {
    $step1 = (int) $m[$i] * (int) $n[$j]; // multiply the ith number of m by the jth number of n
    if (($step1 + $carry) < 10 and $carry != 0) {
      $res .= $step1 + $carry;
      $carry = 0;
    } elseif (($step1 + $carry) >= 10 and $carry != 0) {
      if ($j == strlen($n) - 1) {
        $res .= $step1 + $carry;
        $carry = 0;
      } else {
        $step2 = ($step1 + $carry) % 10; // find the ones part
        $carry = $step1 - $step2; // find the tens part
        $res .= $step2; // increment the result
      }
    } elseif ($step1 < 10 and $carry == 0) $res .= $step1;
    elseif ($step1 >= 10 and $carry == 0) {
      if ($j == strlen($n) - 1) $res .= $step1;
      else {
        $step2 = $step1 % 10; // find the ones part
        $carry = $step1 - $step2; // find the tens part
        $res .= $step2; // increment the result
      }
    }
  }
  // $res = strrev($res);5
  $res .= str_repeat(string: "0", times: $i);
  $final = sum_strings($final, $res);
}

var_export($final);
