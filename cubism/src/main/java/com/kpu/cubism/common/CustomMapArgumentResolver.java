package com.kpu.cubism.common;

import java.util.Enumeration;
import javax.servlet.http.HttpServletRequest;
import org.springframework.core.MethodParameter;
import org.springframework.web.bind.support.WebDataBinderFactory;
import org.springframework.web.context.request.NativeWebRequest;
import org.springframework.web.method.support.HandlerMethodArgumentResolver;
import org.springframework.web.method.support.ModelAndViewContainer;
import com.kpu.cubism.common.CommandMap;

public class CustomMapArgumentResolver implements HandlerMethodArgumentResolver{
    
    //Controller의 파라미터가 CommandMap 클래스인지 검사
    @Override
   public boolean supportsParameter(MethodParameter parameter) {
       return CommandMap.class.isAssignableFrom(parameter.getParameterType());
   }
 
   @Override
   public Object resolveArgument(MethodParameter parameter, ModelAndViewContainer mavContainer, NativeWebRequest webRequest, WebDataBinderFactory binderFactory) throws Exception {
       CommandMap commandMap = new CommandMap();
         
       HttpServletRequest request = (HttpServletRequest) webRequest.getNativeRequest();
       Enumeration<?> enumeration = request.getParameterNames();
         
       String key = null;
       String[] values = null;
       while(enumeration.hasMoreElements()){
           //request에 담긴 모든 키와 값을 commandMap에 저장
           key = (String) enumeration.nextElement();
           values = request.getParameterValues(key);
           if(values != null){
               commandMap.put(key, (values.length > 1) ? values:values[0] );
           }
       }
       return commandMap; //모든 파라미터가 담긴 commandMap에 반환
   }
}