// 뱀이 있는 경우, 0
// 뱀이 없는 경우, 1


let N = null;
let M = null;
let countN = 0;
let data = [];

const dx = [0, 1];
const dy = [1, 0];

const solution = (data, visited) => {
    // 뱀을 피해서 갈 수 있는 경로 여부를 저장하는 변수
    let isPathExist = false;

    function inRange(x, y) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }

    function canGo(x, y) {
        // 범위 밖으로 가는 경우
        if (!inRange(x, y)) {
            return false;
        }
        // 방문했거나 뱀이 존재하는 경우
        else if (visited[x][y] || !data[x][y]) {
            return false;
        }
        else {
            return true;
        }
    }

    const dfs = (x, y) => {
        // 우측 하단에 도달하고 뱀이 존재하지 않는 경우
        if (x === N - 1 && y === M - 1 && data[x][y]) {
            isPathExist = true;
            return;
        }

        for (let i = 0; i < 2; i++) {
            let newX = x + dx[i];
            let newY = y + dy[i];

            if (canGo(newX, newY)) {
                dfs(newX, newY);
                visited[newX, newY] = true;
            }
        }
    }

    visited[0][0] = true;
    dfs(0, 0);

    if (isPathExist) {
        console.log(1);
    }
    else {
        console.log(0);
    }
}

const rl = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout,
});

rl.on('line', (line) => {
    // N, M이 null인 경우
    if (!N && !M) {
        [N, M] = line.split(' ').map(e => +e);
    }
    else {
        data.push(line.split(' ').map(e => +e));
        countN++;
    }

    if (countN === N) {
        rl.close();
    }
});

rl.on('close', () => {
    // solution 실행
    let visited = Array.from(Array(N), () => Array(M).fill(false));
    solution(data, visited);
    process.exit();
});