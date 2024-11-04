"use strict";

// TODO: 製作帳戶
const account1 = {
    owner: "TA01",
    movements: [200, 455.23, -306.5, 25000, -642.21, -133.9, 79.97, 1300],
    interestRate: 1.2, // 利率
    pin: 1111,
    movementsDates: [
        "2019-11-18T21:31:17.178Z",
        "2019-12-23T07:42:02.383Z",
        "2020-01-28T09:15:04.904Z",
        "2020-04-01T10:17:24.185Z",
        "2020-05-08T14:11:59.604Z",
        "2020-07-26T17:01:17.194Z",
        "2020-07-28T23:36:17.929Z",
        "2020-08-01T10:51:36.790Z",
    ],
    currency: "TWD",
    locale: "zh-TW", // de-DE
};

// TODO: 製作帳戶
const account2 = {
    owner: "TA02",
    movements: [5000, 3400, -150, -790, -3210, -1000, 8500, -30],
    interestRate: 1.5, // 利率
    pin: 2222,
    movementsDates: [
        "2019-11-01T13:15:33.035Z",
        "2019-11-30T09:48:16.867Z",
        "2019-12-25T06:04:23.907Z",
        "2020-01-25T14:18:46.235Z",
        "2020-02-05T16:33:06.386Z",
        "2020-04-10T14:43:26.374Z",
        "2020-06-25T18:49:59.371Z",
        "2020-07-26T12:01:20.894Z",
    ],
    currency: "TWD",
    locale: "zh-TW",
};

const accounts = [account1, account2];

//////////////////////////////////////////////////
// element
//////////////////////////////////////////////////
const labelWelcome = document.querySelector(".welcome"); // 左上角
const labelDate = document.querySelector(".date"); // 當前時間
const labelBalance = document.querySelector(".balance__value"); // 當前帳戶金額
const labelSumIn = document.querySelector(".summary__value--in"); // 總收入
const labelSumOut = document.querySelector(".summary__value--out"); // 總支出
const labelSumInterest = document.querySelector(".summary__value--interest"); // 總實際金額
const labelTimer = document.querySelector(".timer"); // 預計登出時間

// 金額明細
const containerApp = document.querySelector(".app");
// 其他轉帳部分
const containerMovements = document.querySelector(".movements");

// 按鈕部分
const btnLogin = document.querySelector(".login__btn"); // 登入按鈕
const btnTransfer = document.querySelector(".form__btn--transfer"); // 轉帳金額
const btnLoan = document.querySelector(".form__btn--loan"); // 申請貸款
const btnClose = document.querySelector(".form__btn--close"); // 關閉帳戶
const btnSort = document.querySelector(".btn--sort"); // 排序
// 輸入欄部分
const inputLoginUsername = document.querySelector(".login__input--user"); // 輸入帳號名稱
const inputLoginPin = document.querySelector(".login__input--pin"); // 輸入PIN
const inputTransferTo = document.querySelector(".form__input--to"); // 輸入欄-轉帳金額
const inputTransferAmount = document.querySelector(".form__input--amount"); // 輸入欄-目標帳戶
const inputLoanAmount = document.querySelector(".form__input--loan-amount"); // 輸入欄-貸款金額
const inputCloseUsername = document.querySelector(".form__input--user"); // 輸入欄-關閉帳號
const inputClosePin = document.querySelector(".form__input--pin"); // 輸入欄-關閉PIN

//////////////////////////////////////////////////
// funtion
//////////////////////////////////////////////////

// TODO: 格式化日期
const formatMovementDate = (date, locale) => {
    // 計算時間差
    daysPassed = Math.round(Math.abs(date - new Date()) / (1000 * 60 * 60 * 24));
    console.log("計算時間差" + daysPassed);
    if (daysPassed === 0) return "Today";
    if (daysPassed === 1) return "Yesterday";
    if (daysPassed <= 7) return `${daysPassed} days ago`;
    // 將指定的日期 date 格式化為 locale 指定的格式。
    return new Intl.DateTimeFormat(locale).format(date);
};

// TODO: 設定貨幣格式化
const formatCur = (value, locale, currency) => {
    return new Intl.NumberFormat(locale, {
        style: "currency",
        currency: currency,
    }).format(value);
};

// TODO: 顯示紀錄(目前帳號資料、排序方式)
const displayMovements = (acc, sort = false) => {
    containerMovements.innerHTML = "";
    // 取出該帳號的資料
    let movs = "";
    if (sort === true) {
        movs = acc.movements.slice().sort((a, b) => {
            b - a;
        });
    } else {
        movs = acc.movements.slice().sort((a, b) => {
            a - b;
        });
    }
    for (let i in movs) {
        // 確認是提款來是存款
        let type = "";
        if (i > 0) type = "deposit";
        else type = "withdrawal";

        // let html = `
        //         <div class="movements__row">
        //             <div class="movements__type movements__type--deposit">存款：2</div>
        //             <div class="movements__date">3 days ago</div>
        //             <div class="movements__value">$400$</div>
        //         </div>`;
    }
};
