function palindrome(str) {
  const len = str.length;
  let flag = true;
  for (let i = 0; i < len / 2; i++) {
    if (str[i] !== str[len - 1 - i]) flag = false;
  }

  if (flag) {
    console.log(true);
  } else {
    console.log(false);
  }
}