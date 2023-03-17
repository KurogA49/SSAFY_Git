import Vue from 'vue'
import VueRouter from 'vue-router'
import HomeView from '../views/HomeView.vue'
// Main, About, Board
import Main from "../views/Main.vue"
import About from "../views/About.vue"
import Board from "../views/Board.vue"

Vue.use(VueRouter)

const routes = [
  // path에 오면 Main에 해당하는 컴포넌트를 보여준다.
  {
    path: "/",
    name: "main",
    component: Main
  },
  {
    path: "/about",
    name: "about",
    component: About
  },
  {
    path: "/board",
    name: "board",
    component: Board
  }
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

export default router
