/**
 * Cubism User message
 * Made by lee tae woong
 */

	$(document).ready(function(){
	$("#user_id_checkBtn").unbind("click").click(function(e){
		e.preventDefault();
		fn_userIDCheck();
	});
});

function fn_userIDCheck() {
  	var token = $("meta[name='_csrf']").attr("content");
  	var header = $("meta[name='_csrf_header']").attr("content");
	var userId = $("#userId").val();
	var userDate = {"userId": userId}
	if(userId.length < 1 )
		{
			alert("아이디를 입력해주세요");
		}
	else
		{
		$.ajax({
			type: "POST",
			url: "/cubism/UserCheck",
			beforeSend : function(xhr)
	         {   /*데이터를 전송하기 전에 헤더에 csrf값을 설정한다*/
	             xhr.setRequestHeader(header, token);
	         },
			data: userDate,
			dataType: "json",
			error: function(xhr, type, error) {
				alert("network error occur");
				console.log('log : ' + type)
	        	console.log('log : ' + xhr)
	        	console.log('message = ' + xhr.responseText)
			},
			
			success: function (result) {
				if(result == 0) 
				{
					$("#userId").attr("disabled", true);
					alert("사용가능한 아이디입니다.");
				} 
				else if(result == 1) 
				{
					alert("이미 존재하는 아이디 입니다. \n다른 아이디를 입력해주세요.");
				}
				else
				{
					alert("Error Occur!" + result);
				}
			}
		});
	}
}