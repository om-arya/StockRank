import { computeMetrics } from '../build/Release/addon';

run();
async function run() {
  const data = await import("./AAPL.csv");
  process(data);
}

//fetch('./data/AAPL.csv')
//.then(aaplData => aaplData.text())
//.then(data => process(data))

function process(data) {
  data = data.replaceAll("\r", "").split("\n").join(",").split(",");
  const aaplDates = data.filter((_, i) => i % 2 == 0);
  const aaplPrices = data.filter((_, i) => i % 2 != 0);
  const result = computeMetrics(aaplPrices);
  console.log(aaplPrices);
  console.log(`The result of the addition is: ${result}`);
}

/*
const graph = document.getElementById('graph');

const xValues = [50,60,70,80,90,100,110,120,130,140,150];
const yValues = [7,8,8,9,9,9,10,11,14,14,15];

new Chart(graph, {
  type: 'line',
  data: {
    labels: xValues,
    datasets: [{
        label: 'Hello',
        data: yValues,
        borderWidth: 1,
        borderColor: 'rgba(168, 205, 149, .1)',
        backgroundColor: 'rgba(168, 205, 149, 1)',
    }]
  },
  options: {
    responsive: true,
    maintainAspectRatio: true,
  }
});
*/