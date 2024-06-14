/*
const csv_file = File('foo.csv');
csv_file.open('r');
csv_file.encoding = 'utf-8';

let data = csv_file.read().split('/\r\n|\n/'); // split by lines
csv_file.close();

for (const row in data) {
    data[row].split(','); // split all lines by commas
}
*/

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

const metrics = require('../build/Release/addon');

const result = metrics.add(5, 3);
console.log(`The result of the addition is: ${result}`);