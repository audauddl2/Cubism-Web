package com.kpu.cubism.common;

import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class CommandMap {
	//절대 Map을 상속받지 않는다!!!
	////상속받게 되면 작성할 ArgumentResolver를 거치지 않게 되므로...
    //이 Map에 모든 데이터를 담는 역할을 한다. 
    Map<String,Object> map = new HashMap<String,Object>();
      
    //기본 Map과 똑같이 사용할 수 있도록 기존 Map의 메소드와 똑같이 작성한다. 
    public Object get(String key){
        return map.get(key);
    }
      
    public void put(String key, Object value){
        map.put(key, value);
    }
      
    public Object remove(String key){
        return map.remove(key);
    }
      
    public boolean containsKey(String key){
        return map.containsKey(key);
    }
      
    public boolean containsValue(Object value){
        return map.containsValue(value);
    }
      
    public void clear(){
        map.clear();
    }
      
    public Set<Entry<String, Object>> entrySet(){
        return map.entrySet();
    }
      
    public Set<String> keySet(){
        return map.keySet();
    }
      
    public boolean isEmpty(){
        return map.isEmpty();
    }
      
    public void putAll(Map<? extends String, ?extends Object> m){
        map.putAll(m);
    }
      
    public Map<String,Object> getMap(){
        return map;
    }
}

