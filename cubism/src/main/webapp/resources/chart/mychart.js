/**
 * Cubism chart
 * use Google Chart
 */

function printTime() {
  var clock = document.getElementById("clock"); // 출력할 장소 선택
  var now = new Date();                         // 현재시간
  var nowTime = now.getFullYear() + "." + (now.getMonth()+1) + "." + now.getDate() + " " + now.getHours() + ":" + now.getMinutes() + ":" + now.getSeconds();
  clock.innerHTML = nowTime;      // 현재시간을 출력
}
window.onload = function() {         // 페이지가 로딩되면 실행
  printTime();
}


var chartDrowFun = {

  chartDrow : function(){
	var queryObject = "";
  	var queryObjectLen = "";
  	var token = $("meta[name='_csrf']").attr("content");
  	var header = $("meta[name='_csrf_header']").attr("content");
  	
  	$.ajax({
         type : 'POST',
         url : '/cubism/chart',
         
         beforeSend : function(xhr)
         {   /*데이터를 전송하기 전에 헤더에 csrf값을 설정한다*/
             xhr.setRequestHeader(header, token);
         },
         dataType : 'json',
         success : function(data) {
        	 console.log('log : ' + data)
             queryObject = eval('(' + JSON.stringify(data,null, 2) + ')');
             queryObjectLen = queryObject.memorylist.length;
             //alert('Total lines : ' + queryObjectLen + 'EA');
         },
         
         error : function(xhr, type) {
        	 //alert('server error occoured')
        	 //alert('error msg : ' + queryObject)
        	 alert('server msg : ' + xhr.status)
        	 console.log('log : ' + type)
        	 console.log('log : ' + xhr)
        	 console.log('message = ' + xhr.responseText)
        	 
         }
  	});

      //날짜형식 변경하고 싶으시면 이 부분 수정하세요.
      //var chartDateformat 	= 'yyyy년MM월dd일';
      var chartDateformat 	= 'M.dd. HH:MM';
      //라인차트의 라인 수
      var chartLineCount    = 10;
      //컨트롤러 바 차트의 라인 수
      var controlLineCount	= 10;


      function drawDashboard() {

        var data = new google.visualization.DataTable();
        data.addColumn('datetime', 'memoryDate');
        data.addColumn('number', '등급');
        data.addColumn('number', '시간 초');
        //data.addColumn('number', 'memorymaxSec');	-> this is previous code 04/29
        //data.addColumn('number', 'memoryminSec');	-> this is previous code 04/29

        //alert('data생성-------------------' + queryObjectLen);
        for (var i = 0; i < queryObjectLen; i++) {
            var memoryDate = queryObject.memorylist[i].memoryDate;
            var memoryRank = queryObject.memorylist[i].memoryRank;
            var memorySec = queryObject.memorylist[i].memorySec;
            //var memorymaxSec = queryObject.memorylist[i].memorymaxSec;	-> this is previous code 04/29
            //var memoryminSec = queryObject.memorylist[i].memoryminSec;	-> this is previous code 04/29
            //alert(mdatecreated + ' ' + Drnpm10Value + ' ' + Drnpm25Value + ' ' + pm10Value + ' ' + pm25Value);
            //data.addRows([ [ new Date(memoryDate), memorySec, memorymaxSec, memoryminSec ] ]);    -> this is previous code 04/29
            data.addRows([ [ new Date(memoryDate), memoryRank, memorySec ] ]);
        }

        var chart = new google.visualization.ChartWrapper({
            chartType   : 'LineChart',
            containerId : 'lineChartArea', //라인 차트 생성할 영역
            options     : {
                isStacked   : 'percent',
                focusTarget : 'category',
                height      : 500,
                width	      : '100%',
                legend      : { position: "top", textStyle: {fontSize: 13}},
                pointSize   : 5,
                tooltip     : {textStyle : {fontSize:12}, showColorCode : true,trigger: 'both'},
                hAxis	: {format: chartDateformat, gridlines:{count:chartLineCount,units: {
                    years : {format: ['yyyy년']},
                    months: {format: ['MM월']},
                    days  : {format: ['dd일']},
                    hours : {format: ['HH시']}}
                    },textStyle: {fontSize:12}},
               vAxis : {minValue: 50,viewWindow:{min:0},gridlines:{count:-1},textStyle:{fontSize:12}},
               animation  : {startup: true,duration: 1000,easing: 'in' },
               annotations: {pattern: chartDateformat,
                    textStyle: {
                    fontSize: 15,
                    bold: true,
                    italic: true,
                    color: '#871b47',
                    auraColor: '#d799ae',
                    opacity: 0.8,
                    pattern: chartDateformat
                    }
                }
            }
        });

        var control = new google.visualization.ControlWrapper({
            controlType: 'ChartRangeFilter',
            containerId: 'controlsArea',  //control bar를 생성할 영역
            options: {
                ui:{
                      chartType: 'LineChart',
                      chartOptions: {
                      chartArea: {'width': '60%','height' : 80},
                        hAxis: {'baselineColor': 'none', format: chartDateformat, textStyle: {fontSize:12},
                      gridlines:{count:controlLineCount,units: {
                           years : {format: ['yyyy년']},
                           months: {format: ['MM월']},
                           days  : {format: ['dd일']},
                           hours : {format: ['HH시']}}
                      }}
                    }
                },
                filterColumnIndex: 0
            }
        });

        var date_formatter = new google.visualization.DateFormat({ pattern: chartDateformat});
        date_formatter.format(data, 0);

        var dashboard = new google.visualization.Dashboard(document.getElementById('Line_Controls_Chart'));
        window.addEventListener('resize', function() { dashboard.draw(data); }, false); //화면 크기에 따라 그래프 크기 변경
        dashboard.bind([control], [chart]);
        dashboard.draw(data);

      }
      google.charts.setOnLoadCallback(drawDashboard);

    }
  }

$(document).ready(function(){
  google.charts.load('current', {
     'packages':['line','controls']
  });
  chartDrowFun.chartDrow(); //chartDrow() 실행
});