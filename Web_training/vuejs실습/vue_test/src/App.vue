<template>
  <div>
    <AppHeader></AppHeader>
    <AppTest></AppTest>
  </div>
</template>

<script>
// 컴포넌트를 가져올 때
// 1. 가져온다 (import from)
// 2. 가져온 컴포넌트를 사용하게끔 components:{}에 등록한다.
// 3. template에서 활용
import AppHeader from "./components/AppHeader.vue";
import AppTest from "./components/AppTest.vue";
export default {
  components: {
    AppHeader,
    AppTest,
  },
};
</script>


<style>
</style>