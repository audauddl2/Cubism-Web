package com.kpu.cubism.controller;

import java.util.List;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.kpu.cubism.service.MemoryService;
import com.kpu.cubism.vo.MemoryVo;


@CrossOrigin(origins ="*")
@Controller
public class MemoryController {
 
	@Autowired
	private MemoryService service;
	
	/*
	 * Chart 출력
	 * 
	 */
	@RequestMapping(value = "/chart", method = RequestMethod.POST)
	@ResponseBody
	public JSONObject getBbsSearch(HttpServletRequest request, HttpServletResponse response, @ModelAttribute MemoryVo vo){
			
		JSONObject responseObj = new JSONObject();
        JSONObject lineObj = null;
        List<MemoryVo> memorylist = service.getMemoryList(vo);
        JSONArray memorylist_json = new JSONArray();
        
        try {
			for(int i = 0; i < memorylist.size(); i++) {
				int memoryIdx = memorylist.get(i).getMemoryIdx();
				String memoryflag = memorylist.get(i).getMemoryflag();
				int memoryRank = memorylist.get(i).getMemoryRank();
				double memorySec = memorylist.get(i).getMemorySec();
				if(memorySec/1000 > 1) {
					memorySec = memorySec / 1000;
				}else 
					memorySec = memorySec / 100;
				
					
				//int memorymaxSec = memorylist.get(i).getMemorymaxSec();
				//int memoryminSec = memorylist.get(i).getMemoryminSec();
				String memoryDate = memorylist.get(i).getMemoryDate();
				
				lineObj = new JSONObject();
	        	lineObj.put("memoryIdx", memoryIdx);
	        	lineObj.put("memoryFlag", memoryflag);
	        	lineObj.put("memoryRank", memoryRank);
	        	lineObj.put("memorySec", memorySec);
	        	//lineObj.put("memorymaxSec", memorymaxSec);
	        	//lineObj.put("memoryminSec", memoryminSec);
	        	lineObj.put("memoryDate", memoryDate);
	        	memorylist_json.add(lineObj);
			}
		    responseObj.put("memorylist", memorylist_json);
		    	
		    //System.out.println(responseObj.toString());
		    //System.out.println();
			
		}catch (Exception e) {
			e.printStackTrace();
		}

		
		return responseObj;
	}
	/*
	 * TEST
	 * 
	 */
	@RequestMapping(value = "/listtest", method = RequestMethod.GET)
	public String list(ModelMap modelMap, @ModelAttribute MemoryVo vo) {

		List<MemoryVo> Memorylist = service.getMemoryList(vo);
		modelMap.addAttribute("list", Memorylist);
		
		return "/test/listtest";
		
	}
}     