// const setRenderBackground = () => {}
async function setRenderBackground() {
  // body background 주소 넣어도 OK

  // 일부러 axios 요청으로 이미지를 받아오기

  // blob: 이미지, 사운드, 비디오 등 멀티미디어 데이터를 다룰 때 사용
  const result = await axios.get("https://picsum.photos/1920/1080", {
    responseType: "blob"
  });
  console.log(result.data);
  // URL.createObjectURL -> 임시 URL을 만들기(페이지 내에서만 유효)
  // 받아온 데이터를 임시 URL로 지정하여 body에 넣기
  const imageUrl = URL.createObjectURL(result.data);
  document.querySelector('body').style.backgroundImage = `url(${imageUrl})`;
}

// 시간 갱신
function setTime() {
  const timer = document.querySelector('.timer');
  setInterval(() => {
    // date 함수
    const date = new Date();
    timer.textContent = `${date.getHours()}:${date.getMinutes()}:${date.getSeconds()}`
  }, 1000);
}

function getMemo() {
  // localStorage로부터 가져와서 memo에 넣어주는 작업
  const memo = document.querySelector('.memo');
  memo.textContent = localStorage.getItem('todo');
}

function setMemo() {
  const memoInput = document.querySelector('.memo-input');

  memoInput.addEventListener("keypress", (e) => {
    // e.code 입력 시 -> 작성한 키보드 조회;
    // ! null undefined false "" -> 부정의 의미
    // e.target.value -> 위 부정의 의미가 아닌 경우를 통합
    // !(e.target.value)
    if(e.code === 'Enter' && e.target.value) {
      // 메모가 날아가지 않도록 저장
      // 원칙적으로는 백엔드에 맡겨야 하지만
      // 브라우저에도 간단한 저장소 개념이 존재 -> localStorage
      // localStorage.setItem('키', '넣을 값')
      localStorage.setItem('todo', e.target.value);
      // localStorage.getItem('키') -> 값을 가져온다
      // getMemo로 분리
      getMemo();

      e.target.value = "";
    }
  });
}

function deleteMemo() {
  // 이벤트 위임
  // document.querySelector('body')

  // 똑같은 함수를 수백만 개에 addEventListener를 단다면 심각한 성능 저하
  document.addEventListener('click', (e) => {
    // e.target.ClassList가 hello인 경우에 ~ 이벤트 실행

    // localStorage를 지우기
    if(e.target.classList.contains('memo')) {
      localStorage.removeItem('todo');

      e.target.textContent = "";
    }
  })
}

function allRender() {
  setRenderBackground();
  setTime();
  getMemo();
  setMemo();
  deleteMemo();

  // 5초마다 해당 콜백 함수를 반복
  setInterval(() => {
    setRenderBackground();
  }, 5000);
}

allRender();
