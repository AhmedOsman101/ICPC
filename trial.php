<?php

declare(strict_types=1);

$n = trim(fgets(STDIN));
$m = trim(fgets(STDIN));

function sum_strings($n, $m): string {
  [$n, $m] = [strrev($n), strrev($m)];
  $res = "";
  $len = max(strlen($n), strlen($m)) + 1;
  $carry = 0;
  for ($i = 0; $i < $len; $i++) {
    $na = isset($n[$i]) ? (int) $n[$i] : 0;
    $nb = isset($m[$i]) ? (int) $m[$i] : 0;
    $sum = $na + $nb + $carry;
    echo "sum:" . $sum . " carry:" . $carry . PHP_EOL;
    if ($sum == 0) {
      $res .= "0";
      continue;
    } elseif ($sum < 10) {
      $res .= $sum;
      $carry = 0;
    } else {
      $res .= $sum - 10;
      $carry = 1;
    }
  }
  $res = ltrim(strrev($res), "0");
  $res = empty($res) ? "0" : $res;

  return $res;
}

function karatsuba($x, $y) {
  if ($x < 10 || $y < 10) return $x * $y;

  $n = max(strlen((string) $x), strlen((string) $y));
  // var_dump($n);

  $half_n = intdiv($n, 2);

  $a = (int) substr(
    string: (string) $x,
    offset: 0,
    length: $half_n
  );

  $b = (int) substr(
    string: (string) $x,
    offset: $half_n
  );

  $c = (int) substr(
    string: (string) $y,
    offset: 0,
    length: $half_n
  );

  $d = (int) substr(
    string: (string) $y,
    offset: $half_n
  );

  var_dump("a: $a, b: $b, c: $c, d: $d");

  $ac = karatsuba($a, $c);
  $bd = karatsuba($b, $d);
  $ad_bc = karatsuba($a + $b, $c + $d) - $ac - $bd;

  var_dump($ac * pow(10, 2 * $half_n) + $ad_bc * pow(10, $half_n) + $bd);

  return $ac * pow(10, 2 * $half_n) + $ad_bc * pow(10, $half_n) + $bd;
}

var_dump(number_format(karatsuba(999_999_999_9, 999_999_999_9)));


// var_dump(sum_strings($n, $m));
