"use strict";

// TODO: Selecting elements
// 整份玩家
const player_0 = document.querySelector(".player--0");
const player_1 = document.querySelector(".player--1");
// 目前分數
const score_0 = document.querySelector("#score--0");
const score_1 = document.querySelector("#score--1");
// 目前次數
const current_0 = document.querySelector("#current--0");
const current_1 = document.querySelector("#current--1");

// 篩子、newGame 、roceDice、HOLD
const dice = document.querySelector(".dice");
const btnNew = document.querySelector(".btn--new");
const btnRoll = document.querySelector(".btn--roll");
const btnHold = document.querySelector(".btn--hold");

let scores, currentScore, activePlayer, playing;

// TODO: 初始化
const init = () => {
    scores = [0, 0];
    currentScore = 0;
    activePlayer = 0;
    playing = true;
    score_0.textContent = 0;
    score_1.textContent = 0;
    current_0.textContent = 0;
    current_1.textContent = 0;
};

// TODO: 切換使用者
const switchPlayer = () => {
    // 切換當下的玩家目前分數先歸0
    document.querySelector(`#current--${activePlayer}`).textContent = 0;
    currentScore = 0;
    // 切換玩家
    if (activePlayer === 0) activePlayer = 1;
    else activePlayer = 0;
    // 切換class => toggle
    player_0.classList.toggle("player--active");
    player_1.classList.toggle("player--active");
};

// TODO: 按下骰子
btnRoll.addEventListener("click", () => {
    if (playing) {
        let dice_temp = Math.trunc(Math.random() * 6) + 1; // 1-6
        console.log(dice_temp);
        //  Display dice
        dice.src = `./img/dice0${dice_temp}.png`;
        if (dice_temp !== 1) {
            currentScore += dice_temp;
            // 切換玩家目前分數
            if (activePlayer === 0) current_0.textContent = currentScore;
            else current_1.textContent = currentScore;
        } else {
            switchPlayer(); //切換玩家
        }
    }
});

// TODO: 按下【下注】按鈕
btnHold.addEventListener("click", () => {
    if (playing) {
        scores[activePlayer] += currentScore;
        // 將目前值存給玩家本身的分數
        if (activePlayer === 0) {
            score_0.textContent = scores[0];
        } else {
            score_1.textContent = scores[1];
        }

        if (scores[activePlayer] >= 50) {
            // finish game
            playing = false;
            if (activePlayer === 0) {
                player_0.classList.add("player--winner");
                player_0.classList.remove("player--active");
            } else {
                player_1.classList.add("player--winner");
                player_1.classList.remove("player--active");
            }
        } else {
            switchPlayer();
        }
    }
});

// TODO: 按下【NEW GAME】
btnNew.addEventListener("click", () => {
    location.reload(); // 重新加載頁面
});

// TODO: main
init();
