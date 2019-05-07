package com.kpu.cubism.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.kpu.cubism.dao.MemoryDao;
import com.kpu.cubism.vo.MemoryVo;


@Service
public class MemoryService {

	@Autowired
	private MemoryDao Memorydao;

	public List<MemoryVo> getMemoryList(MemoryVo vo) {
		
		//System.out.println("Service List Start =================================================");
		return Memorydao.getMemoryList(vo);
	}
	
	public List<MemoryVo> getMemoryChart(MemoryVo vo) {
		
		//System.out.println("Service List Start =================================================");
		return Memorydao.getMemoryChart(vo);
	}

}
