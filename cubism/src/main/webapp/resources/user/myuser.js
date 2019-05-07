/**
 * Cubism User message
 * Made by lee tae woong
 */
$(document).ready(function(){
	$("#signUpBtn").unbind("click").click(function(e){
		e.preventDefault();
		fn_signUp();
	});
});

function fn_signUp() {
	    
	    if($("#userId").val().length < 1)
	    {
	        alert("아이디를 입력해 주세요"); 
	        $("#userId").focus();
	    }
	    else if($("#userPw").val().length < 1)
	    {
	        alert("비밀번호를 입력해 주세요"); 
	        $("#userPw").focus();
	        
	    }
	    else if($("#userName").val().length < 1)
	    {
	        alert("이름을 입력해주세요");
	        $("#userName").focus();
	    }
	    
	    else if($("#userAge").val().length < 1)
	    {
	        alert("나이를 입력해주세요");
	        $("#userAge").focus();
	    }
	    
	    else if($("#userSex").val().length < 1)
	    {
	        alert("성별을 선택해주세요");
	        $("#userSex").focus();
	    }
	    else if(!$("#userId").attr("disabled"))
	    {
	        alert("중복체크를 해주세요");
	    }
	    else
	    {
	    	if(window.confirm("회원가입을 하시겠습니까?"))
	    	{
	    	var comSubmit = new ComSubmit("frm");
	    	comSubmit.setUrl("/cubism/UserRegister");
	    	comSubmit.addParam("userId", $("#userId").val());
	    	comSubmit.submit();
	    	}
	    }
	    
}








